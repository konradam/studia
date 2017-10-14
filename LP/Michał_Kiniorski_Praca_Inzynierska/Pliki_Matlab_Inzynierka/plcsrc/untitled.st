(*
 *
 * File: untitled.st
 *
 * IEC 61131-3 Structured Text (ST) code generated for subsystem "untitled/Regulator LQ"
 *
 * Model name                      : untitled
 * Model version                   : 1.0
 * Model creator                   : Michal
 * Model last modified by          : 
 * Model last modified on          : 
 * Model sample time               : 0s
 * Subsystem name                  : untitled/Regulator LQ
 * Subsystem sample time           : 0.1s
 * Simulink PLC Coder version      : 1.8 (R2014b) 08-Sep-2014
 * ST code generated on            : Fri Nov 27 22:40:07 2015
 *
 * Target IDE selection            : Generic
 * Test Bench included             : No
 *
 *)
FUNCTION_BLOCK Regulator0
VAR_INPUT
    ssMethodType: SINT;
    PVH1: LREAL;
    PVH2: LREAL;
    PVH3: LREAL;
END_VAR
VAR_OUTPUT
    q: LREAL;
END_VAR
VAR
    DiscreteTimeIntegrator_DSTATE: LREAL;
END_VAR
VAR_TEMP
    tmp: LREAL;
END_VAR
CASE ssMethodType OF
    0: 
        
        (* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' *)
        DiscreteTimeIntegrator_DSTATE := 0.0;
    1: 
        
        (* Gain: '<S1>/Gain' incorporates:
         *  Constant: '<S1>/Constant2'
         *  Constant: '<S1>/Constant3'
         *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
         *  Gain: '<S1>/Gain1'
         *  Inport: '<Root>/PV H1'
         *  Inport: '<Root>/PV H3'
         *  Sum: '<S1>/Sum1'
         *  Sum: '<S1>/Sum2' *)
        tmp := (((8.0 - PVH1) * 0.01) + ((2.0 * DiscreteTimeIntegrator_DSTATE) * 0.02)) + ((10.0 - PVH3) * 0.03);
        
        (* Saturate: '<S1>/Ograniczenie sterowania do przedzia³u [0,1]1' incorporates:
         *  Constant: '<S1>/Sterowanie w stanie ustalonym'
         *  Gain: '<S1>/Gain'
         *  Sum: '<S1>/Sum' *)
        IF (tmp + 0.57) >= 1.0 THEN 
            (* Outport: '<Root>/q' *)
            q := 1.0;
        ELSIF (tmp + 0.57) > 0.0 THEN 
            (* Outport: '<Root>/q' *)
            q := tmp + 0.57;
        ELSE 
            (* Outport: '<Root>/q' *)
            q := 0.0;
        END_IF;
        (* End of Saturate: '<S1>/Ograniczenie sterowania do przedzia³u [0,1]1' *)
        
        (* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S1>/Constant1'
         *  Inport: '<Root>/PV H2'
         *  Sum: '<S1>/Sum4' *)
        DiscreteTimeIntegrator_DSTATE := ((14.75 - PVH2) * 0.1) + DiscreteTimeIntegrator_DSTATE;
END_CASE;
END_FUNCTION_BLOCK
VAR_GLOBAL CONSTANT
END_VAR
VAR_GLOBAL
END_VAR
