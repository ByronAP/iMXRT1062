/*
  T41CNC_Pro_25_map.h - driver code for IMXRT1062 processor (on Teensy 4.1 board)

  Part of grblHAL

  !!IMPORTANT!! This map is for T41 CNC Pro 25 board, see https://t41cnc.com for details.

  Board by ByronAP: https://github.com/ByronAP

  Copyright (c) 2025 ByronAP
  Copyright (c) 2020-2024 Terje Io

  grblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grblHAL. If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 2
#error "Axis configuration is not supported!"
#endif

#if QEI_ENABLE && SPINDLE_SYNC_ENABLE
#error "Quadrature encoder and spindle sync cannot be enabled at the same time!"
#endif

#define BOARD_NAME "T41CNCPRO25"
#define BOARD_URL "https://t41cnc.com"

// Define stepper motor pins
#define X_STEP_PIN          (2u)
#define X_DIRECTION_PIN     (3u)
#define X_ENABLE_PIN        (10u)
#define X_LIMIT_PIN         (20u)

#define Y_STEP_PIN          (4u)
#define Y_DIRECTION_PIN     (5u)
#define Y_ENABLE_PIN        (35u)  // Updated from 40u to 35u based on your pinout
#define Y_LIMIT_PIN         (21u)

#define Z_STEP_PIN          (6u)
#define Z_DIRECTION_PIN     (7u)
#define Z_ENABLE_PIN        (39u)
#define Z_LIMIT_PIN         (22u)

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE
#define M3_STEP_PIN         (8u)
#define M3_DIRECTION_PIN    (9u)
#define M3_LIMIT_PIN        (23u)
#define M3_ENABLE_PIN       (38u)
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 2
#define M4_AVAILABLE
#define M4_STEP_PIN         (26u)
#define M4_DIRECTION_PIN    (27u)
#define M4_LIMIT_PIN        (28u)
#define M4_ENABLE_PIN       (37u)
#endif

// Define auxiliary output pins
#define AUXOUTPUT0_PIN      (34u)  // Aux Out 0
#define AUXOUTPUT1_PIN      (32u)  // Aux Out 1
#define AUXOUTPUT2_PIN      (33u)  // Aux Out 2
#define AUXOUTPUT3_PIN      (12u)  // Spindle enable
#define AUXOUTPUT4_PIN      (11u)  // Spindle direction
#define AUXOUTPUT5_PIN      (13u)  // Spindle PWM
#define AUXOUTPUT6_PIN      (19u)  // Coolant flood
#define AUXOUTPUT7_PIN      (18u)  // Coolant mist

// Define driver spindle pins
#if DRIVER_SPINDLE_ENABLE & SPINDLE_ENA
#define SPINDLE_ENABLE_PIN      AUXOUTPUT3_PIN  // Pin 12
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_PWM
#define SPINDLE_PWM_PIN         AUXOUTPUT5_PIN  // Pin 13
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_DIR
#define SPINDLE_DIRECTION_PIN   AUXOUTPUT4_PIN  // Pin 11
#endif

// Define flood and mist coolant enable output pins.
#if COOLANT_ENABLE & COOLANT_FLOOD
#define COOLANT_FLOOD_PIN       AUXOUTPUT6_PIN  // Pin 19
#endif
#if COOLANT_ENABLE & COOLANT_MIST
#define COOLANT_MIST_PIN        AUXOUTPUT7_PIN  // Pin 18
#endif

// Define user-control CONTROLs (cycle start, reset, feed hold, door) input pins.
#define RESET_PIN           (35u)  // Reset on pin 35
#define FEED_HOLD_PIN       (16u)
#define CYCLE_START_PIN     (17u)

// Define auxiliary input pins
#define AUXINPUT0_PIN       (36u)  // Aux In 0 (e.g., MPG mode)
#define AUXINPUT1_PIN       (30u)  // Aux In 1 (e.g., motor fault)
#define AUXINPUT2_PIN       (31u)  // Aux In 2 (e.g., motor warning)
#define AUXINPUT3_PIN       (41u)  // Aux In 3 (e.g., I2C strobe)
#define AUXINPUT4_PIN       (29u)  // Safety door
#define AUXINPUT5_PIN       (15u)  // Probe
#define AUXINPUT6_PIN       (14u)  // Spindle pulse input

#if PROBE_ENABLE
#define PROBE_PIN           AUXINPUT5_PIN  // Pin 15
#endif

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN     AUXINPUT4_PIN  // Pin 29
#endif

#if MPG_ENABLE == 1
#define MPG_MODE_PIN        AUXINPUT0_PIN  // Pin 36
#endif

#if I2C_STROBE_ENABLE
#define I2C_STROBE_PIN      AUXINPUT3_PIN  // Pin 41
#endif

#if MOTOR_FAULT_ENABLE
#define MOTOR_FAULT_PIN     AUXINPUT1_PIN  // Pin 30
#endif

#if MOTOR_WARNING_ENABLE
#define MOTOR_WARNING_PIN   AUXINPUT2_PIN  // Pin 31
#endif

#if QEI_ENABLE
#define QEI_A_PIN           (30u)  // ST1
#define QEI_B_PIN           (34u)  // ST2
#ifdef AUXINPUT3_PIN
#define QEI_SELECT_PIN      AUXINPUT3_PIN  // ST3 (Pin 41)
#endif
#endif

#if SPINDLE_SYNC_ENABLE
#define SPINDLE_INDEX_PIN   (34u)  // ST2
#define SPINDLE_PULSE_PIN   (14u)  // ST3
#endif

#if I2C_ENABLE
#define I2C_PORT            2  // Wire2 for pins 24 (SDA) and 25 (SCL)
#define I2C_SCL2            (25u)  // Not referenced, for info only
#define I2C_SDA2            (24u)  // Not referenced, for info only
#endif