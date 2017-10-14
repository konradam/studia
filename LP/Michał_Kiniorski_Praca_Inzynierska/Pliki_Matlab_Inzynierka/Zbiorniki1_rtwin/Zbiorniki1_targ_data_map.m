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
    ;% Auto data (Zbiorniki1_P)
    ;%
      section.nData     = 78;
      section.data(78)  = dumData; %prealloc
      
	  ;% Zbiorniki1_P.RTDACAnalogInputs_P1_Size
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Zbiorniki1_P.RTDACAnalogInputs_P1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Zbiorniki1_P.RTDACAnalogInputs_P2_Size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Zbiorniki1_P.RTDACAnalogInputs_P2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Zbiorniki1_P.RTDACAnalogInputs_P3_Size
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Zbiorniki1_P.RTDACAnalogInputs_P3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% Zbiorniki1_P.RTDACAnalogInputs_P4_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 13;
	
	  ;% Zbiorniki1_P.RTDACAnalogInputs_P4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 15;
	
	  ;% Zbiorniki1_P.Constant_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 16;
	
	  ;% Zbiorniki1_P.Gain_Gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 17;
	
	  ;% Zbiorniki1_P.Constant5_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 18;
	
	  ;% Zbiorniki1_P.Gain1_Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 19;
	
	  ;% Zbiorniki1_P.Constant6_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 20;
	
	  ;% Zbiorniki1_P.Gain2_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 21;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P1_Size
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 22;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P1
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 24;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P2_Size
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 25;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P2
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 27;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P3_Size
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 28;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P3
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 30;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P4_Size
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 31;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P4
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 33;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P5_Size
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 34;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P5
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 36;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P6_Size
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 37;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P6
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 39;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P7_Size
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 40;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P7
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 42;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P1_Size_k
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 43;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P1_a
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 45;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P2_Size_c
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 46;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P2_a
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 48;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P3_Size_a
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 49;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P3_h
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 51;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P4_Size_c
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 52;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P4_g
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 54;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P5_Size_j
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 55;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P5_o
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 57;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P6_Size_o
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 58;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P6_m
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 60;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P7_Size_l
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 61;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P7_a
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 63;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P1_Size_j
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 64;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P1_j
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 66;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P2_Size_g
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 67;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P2_d
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 69;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P3_Size_o
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 70;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P3_o
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 72;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P4_Size_d
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 73;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P4_a
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 75;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P5_Size_h
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 76;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P5_l
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 78;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P6_Size_g
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 79;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P6_b
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 81;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P7_Size_a
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 82;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P7_e
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 84;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P1_Size_n
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 85;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P1_e
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 87;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P2_Size_e
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 88;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P2_i
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 90;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P3_Size_n
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 91;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P3_g
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 93;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P4_Size_l
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 94;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P4_n
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 96;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P5_Size_i
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 97;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P5_h
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 99;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P6_Size_d
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 100;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P6_h
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 102;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P7_Size_c
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 103;
	
	  ;% Zbiorniki1_P.RTDACPCIPWM_P7_l
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 105;
	
	  ;% Zbiorniki1_P.Constant4_Value
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 106;
	
	  ;% Zbiorniki1_P.SliderGain_Gain
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 107;
	
	  ;% Zbiorniki1_P.Constant1_Value
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 108;
	
	  ;% Zbiorniki1_P.Constant2_Value
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 109;
	
	  ;% Zbiorniki1_P.Constant3_Value
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 110;
	
	  ;% Zbiorniki1_P.SliderGain_Gain_i
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 111;
	
	  ;% Zbiorniki1_P.SliderGain_Gain_l
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 112;
	
	  ;% Zbiorniki1_P.SliderGain_Gain_b
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 113;
	
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
    ;% Auto data (Zbiorniki1_B)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Zbiorniki1_B.RTDACAnalogInputs
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Zbiorniki1_B.Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Zbiorniki1_B.Gain1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Zbiorniki1_B.Gain2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Zbiorniki1_B.SliderGain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Zbiorniki1_B.SliderGain_h
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% Zbiorniki1_B.SliderGain_o
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% Zbiorniki1_B.SliderGain_j
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
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
    ;% Auto data (Zbiorniki1_DWork)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Zbiorniki1_DWork.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Zbiorniki1_DWork.ToWorkspace_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Zbiorniki1_DWork.ToWorkspace1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
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


  targMap.checksum0 = 3203836843;
  targMap.checksum1 = 2263144379;
  targMap.checksum2 = 191951179;
  targMap.checksum3 = 434565771;

