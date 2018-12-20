----------------------------------------------------------------------------------
-- Enginer:        
-- Create Date:    21:19:27 19/12/2018
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
	Signal An :  INTEGER range 0 to 3;
	Signal Bn :  INTEGER range 0 to 3;
	Signal CIn :  INTEGER range 0 to 3;
	Signal F4n :  INTEGER range 0 to 3;
	Signal F5n :  INTEGER range 0 to 3;
	Signal F6n :  INTEGER range 0 to 3;
	Signal F7n :  INTEGER range 0 to 3;
Begin
	An <= CONV_INTEGER(A);
	Bn <= CONV_INTEGER(B);
	CIn <= CONV_INTEGER(CI);

	F4n <= An + Bn + CIn;

	F4 <= CONV_STD_LOGIC_VECTOR(F4n, 3);

	F5n <= An - Bn;

	F5 <= CONV_STD_LOGIC_VECTOR(F5n, 3);

	F6n <= An + 1 + CIn;

	F6 <= CONV_STD_LOGIC_VECTOR(F6n, 3);

	F7n <= Bn - 1 - CIn;

	F7 <= CONV_STD_LOGIC_VECTOR(F7n, 3);

	F <= A Or B When S = "000" else
		  A Nand B When S = "001" else
		  Not A When S = "010" else
		  A Xor B When S = "011" else
		  F4(1)&F4(0) When S = "100" else
		  F5(1)&F5(0) When S = "101" else
		  F6(1)&F6(0) When S = "110" else
		  F7(1)&F7(0);
	CO <= '0' When S = "000" else
		   '0' When S = "001" else
		   '0' When S = "010" else
		   '0' When S = "011" else
		   F4(2) When S = "100" else
		   F5(2) When S = "101" else
		   F6(2) When S = "110" else
		   F7(2);
End Practica6_Arquitectura;
