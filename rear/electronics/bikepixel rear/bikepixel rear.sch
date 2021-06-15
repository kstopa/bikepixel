EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Bike Pixel Rear PCB"
Date "2021-04-12"
Rev "v0.5"
Comp "OpenDev.Consulting"
Comment1 ""
Comment2 "https://bikepixels.com"
Comment3 "License: CERN Open Hardware Licence v1.2 "
Comment4 "Author: Krzysztof Stopa"
$EndDescr
$Comp
L bikepxiel~rear:SW_Push_Dual_Vertical SW1
U 1 1 60777A1F
P 5100 4900
F 0 "SW1" H 5100 5190 50  0000 C CNN
F 1 "mode" H 5100 5099 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Tactile_SPST_Angled_PTS645Vx58-2LFS" H 5550 5200 50  0001 C CNN
F 3 "" H 5550 5200 50  0001 C CNN
	1    5100 4900
	1    0    0    -1  
$EndComp
$Comp
L bikepxiel~rear:SW_Push_Dual_Vertical SW2
U 1 1 6077975F
P 5850 4900
F 0 "SW2" H 5850 5190 50  0000 C CNN
F 1 "color" H 5850 5099 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Tactile_SPST_Angled_PTS645Vx58-2LFS" H 6300 5200 50  0001 C CNN
F 3 "" H 6300 5200 50  0001 C CNN
	1    5850 4900
	1    0    0    -1  
$EndComp
$Comp
L bikepxiel~rear:SW_Push_Dual_Vertical SW3
U 1 1 6077AEBC
P 6600 4900
F 0 "SW3" H 6600 5190 50  0000 C CNN
F 1 "effect" H 6600 5099 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Tactile_SPST_Angled_PTS645Vx58-2LFS" H 7050 5200 50  0001 C CNN
F 3 "" H 7050 5200 50  0001 C CNN
	1    6600 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 60783898
P 5400 3750
F 0 "R2" V 5500 3800 50  0000 C CNN
F 1 "22k" V 5400 3750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5330 3750 50  0001 C CNN
F 3 "~" H 5400 3750 50  0001 C CNN
	1    5400 3750
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 60783D96
P 5400 4200
F 0 "R3" V 5500 4250 50  0000 C CNN
F 1 "10k" V 5400 4200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5330 4200 50  0001 C CNN
F 3 "~" H 5400 4200 50  0001 C CNN
	1    5400 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 60783FAA
P 6900 3200
F 0 "R6" V 7000 3250 50  0000 C CNN
F 1 "470" V 6900 3200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6830 3200 50  0001 C CNN
F 3 "~" H 6900 3200 50  0001 C CNN
	1    6900 3200
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R5
U 1 1 607846D3
P 6900 4200
F 0 "R5" V 7000 4250 50  0000 C CNN
F 1 "10k" V 6900 4200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6830 4200 50  0001 C CNN
F 3 "~" H 6900 4200 50  0001 C CNN
	1    6900 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 60784939
P 6100 4200
F 0 "R4" V 6050 4350 50  0000 C CNN
F 1 "10k" V 6100 4200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6030 4200 50  0001 C CNN
F 3 "~" H 6100 4200 50  0001 C CNN
	1    6100 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 6078E32E
P 5000 3300
F 0 "#PWR0101" H 5000 3050 50  0001 C CNN
F 1 "GND" H 5100 3300 50  0000 C CNN
F 2 "" H 5000 3300 50  0001 C CNN
F 3 "" H 5000 3300 50  0001 C CNN
	1    5000 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 60791BDB
P 4800 5150
F 0 "#PWR0102" H 4800 4900 50  0001 C CNN
F 1 "GND" H 4805 4977 50  0000 C CNN
F 2 "" H 4800 5150 50  0001 C CNN
F 3 "" H 4800 5150 50  0001 C CNN
	1    4800 5150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 60792893
P 5550 5150
F 0 "#PWR0103" H 5550 4900 50  0001 C CNN
F 1 "GND" H 5555 4977 50  0000 C CNN
F 2 "" H 5550 5150 50  0001 C CNN
F 3 "" H 5550 5150 50  0001 C CNN
	1    5550 5150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 60792EB2
P 6300 5150
F 0 "#PWR0104" H 6300 4900 50  0001 C CNN
F 1 "GND" H 6305 4977 50  0000 C CNN
F 2 "" H 6300 5150 50  0001 C CNN
F 3 "" H 6300 5150 50  0001 C CNN
	1    6300 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 4900 4800 4900
Wire Wire Line
	4800 4900 4800 5150
Wire Wire Line
	5400 4900 5300 4900
$Comp
L power:+5V #PWR0105
U 1 1 607ABD8C
P 7300 3500
F 0 "#PWR0105" H 7300 3350 50  0001 C CNN
F 1 "+5V" H 7315 3673 50  0000 C CNN
F 2 "" H 7300 3500 50  0001 C CNN
F 3 "" H 7300 3500 50  0001 C CNN
	1    7300 3500
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 607AD441
P 7600 3500
F 0 "#PWR0106" H 7600 3250 50  0001 C CNN
F 1 "GND" H 7605 3327 50  0000 C CNN
F 2 "" H 7600 3500 50  0001 C CNN
F 3 "" H 7600 3500 50  0001 C CNN
	1    7600 3500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0107
U 1 1 607AEFCB
P 5650 3550
F 0 "#PWR0107" H 5650 3400 50  0001 C CNN
F 1 "+5V" V 5700 3550 50  0000 L CNN
F 2 "" H 5650 3550 50  0001 C CNN
F 3 "" H 5650 3550 50  0001 C CNN
	1    5650 3550
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0108
U 1 1 607AFAF7
P 5400 4000
F 0 "#PWR0108" H 5400 3850 50  0001 C CNN
F 1 "+5V" H 5300 4100 50  0000 C CNN
F 2 "" H 5400 4000 50  0001 C CNN
F 3 "" H 5400 4000 50  0001 C CNN
	1    5400 4000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0109
U 1 1 607B193C
P 6100 4000
F 0 "#PWR0109" H 6100 3850 50  0001 C CNN
F 1 "+5V" H 6100 4150 50  0000 C CNN
F 2 "" H 6100 4000 50  0001 C CNN
F 3 "" H 6100 4000 50  0001 C CNN
	1    6100 4000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0110
U 1 1 607B24A4
P 6900 4000
F 0 "#PWR0110" H 6900 3850 50  0001 C CNN
F 1 "+5V" H 6800 4100 50  0000 C CNN
F 2 "" H 6900 4000 50  0001 C CNN
F 3 "" H 6900 4000 50  0001 C CNN
	1    6900 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 4900 6800 4900
Wire Wire Line
	6300 5150 6300 4900
Wire Wire Line
	6300 4900 6400 4900
Wire Wire Line
	5550 5150 5550 4900
Wire Wire Line
	5550 4900 5650 4900
$Comp
L Connector:Conn_01x07_Female J2
U 1 1 60785D6E
P 6200 2950
F 0 "J2" V 6365 2930 50  0000 C CNN
F 1 "Arduino" V 6274 2930 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x07_P2.54mm_Vertical" H 6200 2950 50  0001 C CNN
F 3 "~" H 6200 2950 50  0001 C CNN
	1    6200 2950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 6077F31E
P 5400 3200
F 0 "R1" V 5500 3250 50  0000 C CNN
F 1 "22k" V 5400 3200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5330 3200 50  0001 C CNN
F 3 "~" H 5400 3200 50  0001 C CNN
	1    5400 3200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6900 4350 6900 4450
Wire Wire Line
	5400 4350 5400 4450
Wire Wire Line
	6400 3150 6400 4450
Wire Wire Line
	6400 4450 6900 4450
Connection ~ 6900 4450
Wire Wire Line
	6900 4450 6900 4900
Wire Wire Line
	5400 4450 6000 4450
Wire Wire Line
	6000 4450 6000 3150
Connection ~ 5400 4450
Wire Wire Line
	5400 4450 5400 4900
$Comp
L Connector:Conn_01x03_Female J1
U 1 1 60819283
P 4900 2950
F 0 "J1" V 4850 3250 50  0000 R CNN
F 1 "Power" V 4750 3350 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 4900 2950 50  0001 C CNN
F 3 "~" H 4900 2950 50  0001 C CNN
	1    4900 2950
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x03_Female J3
U 1 1 6081A6C5
P 7400 2950
F 0 "J3" V 7338 2762 50  0000 R CNN
F 1 "Matrix" V 7247 2762 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 7400 2950 50  0001 C CNN
F 3 "~" H 7400 2950 50  0001 C CNN
	1    7400 2950
	0    -1   -1   0   
$EndComp
$Comp
L bikepxiel~rear:SW_SPDT SW0
U 1 1 6081C4BB
P 5350 3450
F 0 "SW0" H 5150 3550 50  0000 L CNN
F 1 "on/off" H 5600 3500 50  0000 L CNN
F 2 "bikepixel rear:SW-SPDT-SS12D00-Angled" H 5350 3450 50  0001 C CNN
F 3 "" H 5350 3450 50  0001 C CNN
	1    5350 3450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0112
U 1 1 60830BAD
P 6100 3450
F 0 "#PWR0112" H 6100 3300 50  0001 C CNN
F 1 "+5V" H 6115 3623 50  0000 C CNN
F 2 "" H 6100 3450 50  0001 C CNN
F 3 "" H 6100 3450 50  0001 C CNN
	1    6100 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	7400 3150 7400 3350
Wire Wire Line
	7400 3350 7300 3350
Wire Wire Line
	7500 3150 7500 3350
Wire Wire Line
	7500 3350 7600 3350
$Comp
L Device:C C1
U 1 1 60774152
P 7450 3450
F 0 "C1" V 7350 3700 50  0000 C CNN
F 1 "470uF, 6.3V" V 7450 3900 50  0000 C CNN
F 2 "Capacitor_THT:C_Radial_D8.0mm_H7.0mm_P3.50mm" H 7488 3300 50  0001 C CNN
F 3 "~" H 7450 3450 50  0001 C CNN
	1    7450 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	7300 3350 7300 3450
Wire Wire Line
	7600 3350 7600 3450
Wire Wire Line
	7300 3450 7300 3500
Connection ~ 7300 3450
Wire Wire Line
	7600 3450 7600 3500
Connection ~ 7600 3450
Wire Wire Line
	5900 3150 5900 3200
Wire Wire Line
	5000 3150 5000 3200
Wire Wire Line
	5900 3200 5550 3200
Wire Wire Line
	5250 3200 5000 3200
Wire Wire Line
	5000 3200 5000 3300
Connection ~ 5000 3200
Wire Wire Line
	5400 4050 5400 4000
Wire Wire Line
	6900 4050 6900 4000
Wire Wire Line
	5550 3550 5650 3550
Wire Wire Line
	5150 3450 4900 3450
Wire Wire Line
	4900 3450 4900 3150
Wire Wire Line
	4800 3150 4800 3750
Wire Wire Line
	5900 3200 5900 3750
Connection ~ 5900 3200
Wire Wire Line
	5550 3750 5900 3750
Wire Wire Line
	5250 3750 4800 3750
Wire Wire Line
	6100 3150 6100 3450
Text Notes 8000 3150 0    39   ~ 0
Note that in the matrix specs a 1000 uF \ncapacitator is recommended but due to \nsize restrctions a smaller one is used.
Wire Wire Line
	6100 4000 6100 4050
Wire Wire Line
	6100 4350 6100 4450
Wire Wire Line
	6100 4900 6050 4900
Wire Wire Line
	6100 4450 6200 4450
Wire Wire Line
	6200 3150 6200 4450
Connection ~ 6100 4450
Wire Wire Line
	6100 4450 6100 4900
$Comp
L power:GND #PWR?
U 1 1 60C2CA88
P 6300 3450
F 0 "#PWR?" H 6300 3200 50  0001 C CNN
F 1 "GND" H 6305 3277 50  0000 C CNN
F 2 "" H 6300 3450 50  0001 C CNN
F 3 "" H 6300 3450 50  0001 C CNN
	1    6300 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 3150 6300 3450
Wire Wire Line
	7050 3200 7300 3200
Wire Wire Line
	7300 3200 7300 3150
Wire Wire Line
	6750 3200 6500 3200
Wire Wire Line
	6500 3200 6500 3150
$EndSCHEMATC
