(*
 *
 * File: obsluga_analogow.st
 *
 * IEC 61131-3 Structured Text (ST) code generated for subsystem "obsluga_analogow/obsluga_analogow"
 *
 * Model name                      : obsluga_analogow
 * Model version                   : 1.5
 * Model creator                   : Michal
 * Model last modified by          : Michal
 * Model last modified on          : Mon Dec 28 16:05:02 2015
 * Model sample time               : 0s
 * Subsystem name                  : obsluga_analogow/obsluga_analogow
 * Subsystem sample time           : 0.2s
 * Simulink PLC Coder version      : 1.8 (R2014b) 08-Sep-2014
 * ST code generated on            : Sat Jan 09 05:57:15 2016
 *
 * Target IDE selection            : Phoenix Contact PC WORX 6.0
 * Test Bench included             : No
 *
 *)
FUNCTION_BLOCK obsluga_analogow0
VAR_INPUT
    analog_1: REAL;
    analog_2: REAL;
    analog_3: REAL;
END_VAR
VAR_OUTPUT
    Poziomgrnyzbiornik: REAL;
    Poziomrodkowyzbiornik: REAL;
    Poziomdolnyzbiornik: REAL;
END_VAR
VAR
END_VAR
VAR_TEMP
END_VAR
Poziomgrnyzbiornik := ((analog_1 / 2947.9) * 15.6645) + -0.5253;
Poziomrodkowyzbiornik := ((analog_2 / 2941.0) * 15.4212) + -0.0352;
Poziomdolnyzbiornik := (((analog_3 - 2960.0) / 3067.6) * 25.129) + -24.1137;
END_FUNCTION_BLOCK
VAR_GLOBAL CONSTANT
END_VAR
VAR_GLOBAL
END_VAR
