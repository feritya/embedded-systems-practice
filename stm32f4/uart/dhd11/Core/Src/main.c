/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  */
/* USER CODE END Header */

#include "main.h"
#include <stdint.h>

/* Private macro -------------------------------------------------------------*/
#define DHT_PORT GPIOA
#define DHT_PIN  GPIO_PIN_1

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim7;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM6_Init(void);
static void MX_TIM7_Init(void);

/* Delay prototypes */
void delay_us(uint32_t us);
void delay_ms(uint32_t ms);

/* DHT helpers */
void DHT11_Pin_Output(void);
void DHT11_Pin_Input(void);
void DHT11_Start(void);
uint8_t DHT11_Read(uint8_t *temperature, uint8_t *humidity);

/* -------------------- IMPLEMENTATION -------------------- */

// Timer 7 ile ms delay
// TIM7 PSC = 8399 -> tick = 0.1 ms (10 kHz) => ms * 10 ticks
void delay_ms(uint32_t ms) {
    __HAL_TIM_SET_COUNTER(&htim7, 0);
    while (__HAL_TIM_GET_COUNTER(&htim7) < (ms * 10));
}

// Timer 6 ile us delay
// TIM6 PSC = 83 -> tick = 1 us (1 MHz)
void delay_us(uint32_t us) {
    __HAL_TIM_SET_COUNTER(&htim6, 0);
    while (__HAL_TIM_GET_COUNTER(&htim6) < us);
}

// DATA pinini output (open-drain) yap
void DHT11_Pin_Output(void){
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DHT_PIN;
    // open-drain recommended for bus lines
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    // Eğer sistemde dış pull-up yoksa iç pull-up kullanabilirsin; dış pull-up(10k) daha güvenli
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(DHT_PORT, &GPIO_InitStruct);
}

// DATA pinini input yap
void DHT11_Pin_Input(void){
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DHT_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    // DHT hattı için pull-up gereklidir (dış 10k önerilir). Eğer yoksa burayı GPIO_PULLUP yap.
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(DHT_PORT, &GPIO_InitStruct);
}

// Start sinyali gönder: LOW ~18ms, sonra HIGH 20-40us, sonra input
void DHT11_Start(void)
{
    DHT11_Pin_Output();
    HAL_GPIO_WritePin(DHT_PORT, DHT_PIN, GPIO_PIN_RESET); // LOW
    delay_ms(18);                                         // ~18ms
    HAL_GPIO_WritePin(DHT_PORT, DHT_PIN, GPIO_PIN_SET);   // HIGH
    delay_us(30);                                         // 20-40us
    DHT11_Pin_Input();                                    // DHT cevap versin
}

// DHT11 oku: temperature ve humidity pointer'larına yaz. Dönen 1=OK, 0=Hata
uint8_t DHT11_Read(uint8_t *temperature, uint8_t *humidity)
{
    uint8_t data[5] = {0};
    uint8_t i;
    uint32_t pulse;
    uint32_t timeout;

    DHT11_Start();

    // --- DHT cevap (80us LOW, 80us HIGH) ---
    timeout = 0;
    // Wait for DHT to pull line LOW (response start)
    while (HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN) == GPIO_PIN_SET) {
        delay_us(1);
        if (++timeout > 1000) return 0; // timeout ~1ms
    }

    timeout = 0;
    // Wait for response LOW to finish (rising edge)
    while (HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN) == GPIO_PIN_RESET) {
        delay_us(1);
        if (++timeout > 1000) return 0;
    }

    timeout = 0;
    // Wait for response HIGH to finish (falling edge) -> now first bit starts
    while (HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN) == GPIO_PIN_SET) {
        delay_us(1);
        if (++timeout > 1000) break;
    }

    // --- Read 40 bits ---
    for (i = 0; i < 40; i++) {
        // Wait for line to go LOW (start of bit)
        timeout = 0;
        while (HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN) == GPIO_PIN_RESET) {
            delay_us(1);
            if (++timeout > 1000) return 0;
        }
        // Wait for line to go HIGH (end of 50us LOW, beginning of the 'value' pulse)
        timeout = 0;
        while (HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN) == GPIO_PIN_SET) {
            // Actually we should wait for low->high transition first; but if we reached here means it's high,
            // so break to measure it below. This loop guards excessive busy-wait before measurement.
            break;
        }

        // Now measure duration of HIGH pulse
        __HAL_TIM_SET_COUNTER(&htim6, 0); // start timer6
        // Wait while line is HIGH and let timer run
        while (HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN) == GPIO_PIN_SET) {
            if (__HAL_TIM_GET_COUNTER(&htim6) > 200) break; // safety
        }
        pulse = __HAL_TIM_GET_COUNTER(&htim6);

        // If HIGH pulse long -> bit = 1. DHT11: ~26-28us for 0, ~70us for 1.
        if (pulse > 40) { // threshold = 40 us (tweak if needed)
            data[i / 8] |= (1 << (7 - (i % 8)));
        }

        // Wait end of this HIGH so next loop syncs to next LOW
        timeout = 0;
        while (HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN) == GPIO_PIN_SET) {
            delay_us(1);
            if (++timeout > 1000) break;
        }
    }

    // checksum
    if (data[4] == (uint8_t)((data[0] + data[1] + data[2] + data[3]) & 0xFF)) {
        *humidity = data[0];
        *temperature = data[2];
        return 1;
    }

    return 0;
}

/* USER CODE END PFP */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  uint8_t temperature=0, humidity=0;
  uint8_t ok;

  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_TIM6_Init();
  MX_TIM7_Init();

  // Start timers (so delay_* kullanabiliriz)ö
  HAL_TIM_Base_Start(&htim6);
  HAL_TIM_Base_Start(&htim7);

  while (1)
  {
      ok = DHT11_Read(&temperature, &humidity);
      if (ok) {
          // Başarılı okuma -> temperature ve humidity kullanılabilir
          // Debug için buraya UART/printf koyabilirsin.
      } else {
          // Okuma hatası
      }

      HAL_Delay(1000); // DHT11'i 1s'den sık okuma
  }
}

/* ------------- GENERATED/MX functions below - sadece PSC güncellemesi gerekti ------------- */

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 84;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) Error_Handler();

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2; // APB1 prescaler 2
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) Error_Handler();
}

/**
  * @brief TIM6 Initialization Function
  * TIM6 prescaler = 83 -> 84MHz/(83+1) = 1 MHz -> 1 us tick
  */
static void MX_TIM6_Init(void)
{
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 83;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 65535;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK) Error_Handler();
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK) Error_Handler();
}
void Error_Handler(void)
{
  __disable_irq();   // Tüm interruptları kapat
  while (1)
  {
    // Hata durumunda burada kalır
  }
}

/**
  * @brief TIM7 Initialization Function
  * TIM7 prescaler = 8399 -> 84MHz/(8399+1)=10 kHz -> 0.1 ms tick
  */
static void MX_TIM7_Init(void)
{
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  htim7.Instance = TIM7;
  htim7.Init.Prescaler = 8399;
  htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim7.Init.Period = 65535;
  htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim7) != HAL_OK) Error_Handler();
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK) Error_Handler();
}

/**
  * @brief GPIO Initialization Function
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* Configure PA1 as input with pull-up initially */
  GPIO_InitStruct.Pin = DHT_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP; // önerilen: DHT hattı pull-up ile kullanılmalı
  HAL_GPIO_Init(DHT_PORT, &GPIO_InitStruct);
}
