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
    ;% Auto data (Zbiorniki_lqr_P)
    ;%
      section.nData     = 79;
      section.data(79)  = dumData; %prealloc
      
	  ;% Zbiorniki_lqr_P.K
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Zbiorniki_lqr_P.pooled1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Zbiorniki_lqr_P.T0
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Zbiorniki_lqr_P.ZaworGORA_gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% Zbiorniki_lqr_P.ZaworSRODEK_gain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% Zbiorniki_lqr_P.ZaworDOL_gain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% Zbiorniki_lqr_P.RTDACAnalogInputs_P1_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% Zbiorniki_lqr_P.RTDACAnalogInputs_P1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% Zbiorniki_lqr_P.RTDACAnalogInputs_P2_Size
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% Zbiorniki_lqr_P.RTDACAnalogInputs_P2
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 14;
	
	  ;% Zbiorniki_lqr_P.RTDACAnalogInputs_P3_Size
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 17;
	
	  ;% Zbiorniki_lqr_P.RTDACAnalogInputs_P3
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 19;
	
	  ;% Zbiorniki_lqr_P.RTDACAnalogInputs_P4_Size
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 22;
	
	  ;% Zbiorniki_lqr_P.RTDACAnalogInputs_P4
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 24;
	
	  ;% Zbiorniki_lqr_P.Constant_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 25;
	
	  ;% Zbiorniki_lqr_P.Gain_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 26;
	
	  ;% Zbiorniki_lqr_P.Constant5_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 27;
	
	  ;% Zbiorniki_lqr_P.Gain1_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 28;
	
	  ;% Zbiorniki_lqr_P.Constant6_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 29;
	
	  ;% Zbiorniki_lqr_P.Gain2_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 30;
	
	  ;% Zbiorniki_lqr_P.Constant1_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 31;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P1_Size
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 32;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P1
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 34;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P2_Size
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 35;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P2
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 37;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P3_Size
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 38;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P3
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 40;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P4_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 41;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P4
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 43;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P5_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 44;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P5
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 46;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P6_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 47;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P6
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 49;
	
	  ;% Zbiorniki_lqr_P.Constant2_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 50;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P1_Size_o
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 51;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P1_c
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 53;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P2_Size_o
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 54;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P2_f
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 56;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P3_Size_k
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 57;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P3_f
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 59;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P4_Size_m
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 60;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P4_m
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 62;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P5_Size_h
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 63;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P5_b
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 65;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P6_Size_j
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 66;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P6_j
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 68;
	
	  ;% Zbiorniki_lqr_P.Constant3_Value
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 69;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P1_Size_d
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 70;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P1_o
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 72;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P2_Size_g
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 73;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P2_a
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 75;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P3_Size_g
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 76;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P3_c
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 78;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P4_Size_f
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 79;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P4_j
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 81;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P5_Size_e
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 82;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P5_e
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 84;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P6_Size_l
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 85;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P6_k
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 87;
	
	  ;% Zbiorniki_lqr_P.TransferFcn_A
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 88;
	
	  ;% Zbiorniki_lqr_P.TransferFcn_C
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 89;
	
	  ;% Zbiorniki_lqr_P.TransferFcn1_A
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 90;
	
	  ;% Zbiorniki_lqr_P.TransferFcn1_C
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 91;
	
	  ;% Zbiorniki_lqr_P.TransferFcn2_A
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 92;
	
	  ;% Zbiorniki_lqr_P.TransferFcn2_C
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 93;
	
	  ;% Zbiorniki_lqr_P.Constant7_Value
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 94;
	
	  ;% Zbiorniki_lqr_P.Gain4_Gain
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 97;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P1_Size_e
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 98;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P1_f
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 100;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P2_Size_b
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 101;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P2_m
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 103;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P3_Size_f
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 104;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P3_b
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 106;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P4_Size_p
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 107;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P4_f
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 109;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P5_Size_g
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 110;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P5_b0
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 112;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P6_Size_n
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 113;
	
	  ;% Zbiorniki_lqr_P.RTDACPCIPWM_P6_m
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 115;
	
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
    ;% Auto data (Zbiorniki_lqr_B)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% Zbiorniki_lqr_B.RTDACAnalogInputs
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Zbiorniki_lqr_B.Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Zbiorniki_lqr_B.Gain1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Zbiorniki_lqr_B.Gain2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Zbiorniki_lqr_B.SliderGain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Zbiorniki_lqr_B.SliderGain_a
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% Zbiorniki_lqr_B.SliderGain_ap
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% Zbiorniki_lqr_B.TransferFcn
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% Zbiorniki_lqr_B.TransferFcn1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% Zbiorniki_lqr_B.TransferFcn2
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% Zbiorniki_lqr_B.Gain3
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% Zbiorniki_lqr_B.Gain4
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% Zbiorniki_lqr_B.TmpSignalConversionAtToWorkspac
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
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
    ;% Auto data (Zbiorniki_lqr_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Zbiorniki_lqr_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Zbiorniki_lqr_DW.ToWorkspace_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Zbiorniki_lqr_DW.Scope1_PWORK.LoggedData
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


  targMap.checksum0 = 3698188970;
  targMap.checksum1 = 2548717112;
  targMap.checksum2 = 3255192275;
  targMap.checksum3 = 1220069499;

