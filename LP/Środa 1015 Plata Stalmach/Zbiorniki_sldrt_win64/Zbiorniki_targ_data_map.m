  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Zbiorniki_P)
    ;%
      section.nData     = 78;
      section.data(78)  = dumData; %prealloc
      
	  ;% Zbiorniki_P.pooled1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Zbiorniki_P.T0
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Zbiorniki_P.ZaworGORA_gain
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Zbiorniki_P.ZaworSRODEK_gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Zbiorniki_P.ZaworDOL_gain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% Zbiorniki_P.Pompa_gain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% Zbiorniki_P.RTDACAnalogInputs_P1_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% Zbiorniki_P.RTDACAnalogInputs_P1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% Zbiorniki_P.RTDACAnalogInputs_P2_Size
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% Zbiorniki_P.RTDACAnalogInputs_P2
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% Zbiorniki_P.RTDACAnalogInputs_P3_Size
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% Zbiorniki_P.RTDACAnalogInputs_P3
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 17;
	
	  ;% Zbiorniki_P.RTDACAnalogInputs_P4_Size
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 20;
	
	  ;% Zbiorniki_P.RTDACAnalogInputs_P4
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 22;
	
	  ;% Zbiorniki_P.Constant_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 23;
	
	  ;% Zbiorniki_P.Gain_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 24;
	
	  ;% Zbiorniki_P.Constant5_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 25;
	
	  ;% Zbiorniki_P.Gain1_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 26;
	
	  ;% Zbiorniki_P.Constant6_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 27;
	
	  ;% Zbiorniki_P.Gain2_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 28;
	
	  ;% Zbiorniki_P.TransferFcn_A
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 29;
	
	  ;% Zbiorniki_P.TransferFcn_C
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 30;
	
	  ;% Zbiorniki_P.TransferFcn1_A
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 31;
	
	  ;% Zbiorniki_P.TransferFcn1_C
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 32;
	
	  ;% Zbiorniki_P.TransferFcn2_A
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 33;
	
	  ;% Zbiorniki_P.TransferFcn2_C
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 34;
	
	  ;% Zbiorniki_P.Constant1_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 35;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P1_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 36;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 38;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P2_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 39;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P2
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 41;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P3_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 42;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P3
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 44;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P4_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 45;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P4
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 47;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P5_Size
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 48;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P5
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 50;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P6_Size
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 51;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P6
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 53;
	
	  ;% Zbiorniki_P.Constant2_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 54;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P1_Size_o
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 55;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P1_c
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 57;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P2_Size_o
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 58;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P2_f
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 60;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P3_Size_k
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 61;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P3_f
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 63;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P4_Size_m
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 64;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P4_m
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 66;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P5_Size_h
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 67;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P5_b
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 69;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P6_Size_j
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 70;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P6_j
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 72;
	
	  ;% Zbiorniki_P.Constant3_Value
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 73;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P1_Size_d
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 74;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P1_o
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 76;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P2_Size_g
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 77;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P2_a
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 79;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P3_Size_g
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 80;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P3_c
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 82;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P4_Size_f
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 83;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P4_j
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 85;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P5_Size_e
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 86;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P5_e
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 88;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P6_Size_l
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 89;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P6_k
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 91;
	
	  ;% Zbiorniki_P.Constant4_Value
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 92;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P1_Size_e
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 93;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P1_f
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 95;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P2_Size_b
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 96;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P2_m
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 98;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P3_Size_f
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 99;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P3_b
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 101;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P4_Size_p
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 102;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P4_f
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 104;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P5_Size_g
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 105;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P5_b0
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 107;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P6_Size_n
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 108;
	
	  ;% Zbiorniki_P.RTDACPCIPWM_P6_m
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 110;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Zbiorniki_B)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% Zbiorniki_B.RTDACAnalogInputs
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Zbiorniki_B.Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Zbiorniki_B.Gain1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Zbiorniki_B.Gain2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Zbiorniki_B.TransferFcn
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Zbiorniki_B.TransferFcn1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% Zbiorniki_B.TransferFcn2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% Zbiorniki_B.SliderGain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% Zbiorniki_B.SliderGain_a
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% Zbiorniki_B.SliderGain_ap
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% Zbiorniki_B.SliderGain_ay
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Zbiorniki_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Zbiorniki_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 268753180;
  targMap.checksum1 = 30500407;
  targMap.checksum2 = 2624192489;
  targMap.checksum3 = 2232904599;

