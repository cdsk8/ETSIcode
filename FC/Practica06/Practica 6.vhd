----------------------------------------------------------------------------------
-- Enginer:        
-- Create Date:    23:06:15 06/01/2019
-- Module Name:    Practica6 - Practica6_Arquitectura
-- Project Name:   Practica 6.vme
-- Description:    
--
-- Created with VHDL ME. Parser by B0vE, powered by Temis (De mesa)
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

Entity Practica6 is
	Port( A : In STD_LOGIC_VECTOR(1 downto 0);
		   B : In STD_LOGIC_VECTOR(1 downto 0);
		   F : Out STD_LOGIC_VECTOR(1 downto 0);
		   CI : In STD_LOGIC;
		   CO : Out STD_LOGIC;
		   S : In STD_LOGIC_VECTOR(2 downto 0));
End Practica6;

Architecture Practica6_Arquitectura of Practica6 is
	Signal F4 :  STD_LOGIC_VECTOR(2 downto 0);
	Signal F5 :  STD_LOGIC_VECTOR(2 downto 0);
	Signal F6 :  STD_LOGIC_VECTOR(2 downto 0);
	Signal F7 :  STD_LOGIC_VECTOR(2 downto 0);
Begin
	F4 <= ('0'&A) + ('0'&B) + ('0'&CI);
	F5 <= ('0'&A) - ('0'&B);
	F6 <= ('0'&A) + 1 + ('0'&CI);
	F7 <= ('0'&B) - 1 - ('0'&CI);

	F <= A Or B When S = "000" else
		  A Nand B When S = "001" else
		  Not A When S = "010" else
		  A Xor B When S = "011" else
		  F4(1)&F4(0) When S = "100" else
		  F5(1)&F5(0) When S = "101" else
		  F6(1)&F6(0) When S = "110" else
		  F7(1)&F7(0);
	CO <= 'X' When S = "000" else
		   'X' When S = "001" else
		   'X' When S = "010" else
		   'X' When S = "011" else
		   F4(2) When S = "100" else
		   F5(2) When S = "101" else
		   F6(2) When S = "110" else
		   F7(2);
End Practica6_Arquitectura;

--#Implementation, copy this into constrictions file and remove '--' coments.
--NET "A(1)" LOC = "B4"  | IOSTANDARD = LVTTL | SLEW = SLOW | DRIVE = 6 ;
--NET "A(0)" LOC = "A4"  | IOSTANDARD = LVTTL | SLEW = SLOW | DRIVE = 6 ;
--NET "B(1)" LOC = "D5"  | IOSTANDARD = LVTTL | SLEW = SLOW | DRIVE = 6 ;
--NET "B(0)" LOC = "C5"  | IOSTANDARD = LVTTL | SLEW = SLOW | DRIVE = 6 ;
--NET "S(0)" LOC = "L13"  | IOSTANDARD = LVTTL | PULLUP ;
--NET "S(1)" LOC = "L14"  | IOSTANDARD = LVTTL | PULLUP ;
--NET "S(2)" LOC = "H18"  | IOSTANDARD = LVTTL | PULLUP ;
--NET "CI" LOC = "N17"  | IOSTANDARD = LVTTL | PULLUP ;
--NET "F(0)" LOC = "F12"  | IOSTANDARD = LVTTL | SLEW = SLOW | DRIVE = 8 ;
--NET "F(1)" LOC = "E12"  | IOSTANDARD = LVTTL | SLEW = SLOW | DRIVE = 8 ;
--NET "CO" LOC = "E11"  | IOSTANDARD = LVTTL | SLEW = SLOW | DRIVE = 8 ;
--#Implementation finished
