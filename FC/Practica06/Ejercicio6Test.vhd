LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Ejercicio5Test IS
END Ejercicio5Test;
 
ARCHITECTURE behavior OF Ejercicio5Test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Practica6
    PORT(
         A : IN  std_logic_vector(1 downto 0);
         B : IN  std_logic_vector(1 downto 0);
         F : OUT  std_logic_vector(1 downto 0);
         CI : IN  std_logic;
         CO : OUT  std_logic;
         S : IN  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(1 downto 0) := (others => '0');
   signal B : std_logic_vector(1 downto 0) := (others => '0');
   signal CI : std_logic := '0';
   signal S : std_logic_vector(2 downto 0) := (others => '0');

 	--Outputs
   signal F : std_logic_vector(1 downto 0);
   signal CO : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Practica6 PORT MAP (
          A => A,
          B => B,
          F => F,
          CI => CI,
          CO => CO,
          S => S
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		
		S <= "000"; --Operación: A Or B
		A <= "00"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO X F 00
		A <= "00"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO X F 01
		A <= "00"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO X F 10
		A <= "00"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "01"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO X F 01
		A <= "01"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO X F 01
		A <= "01"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "01"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "10"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO X F 10
		A <= "10"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "10"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "10"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "11"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "11"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "11"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "11"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO X F 11
		
		S <= "001"; --Operación: A Nand B
		A <= "00"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "00"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "00"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "00"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "01"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "01"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO X F 10
		A <= "01"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "01"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO X F 10
		A <= "10"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "10"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "10"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO X F 01
		A <= "10"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO X F 01
		A <= "11"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "11"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO X F 10
		A <= "11"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO X F 01
		A <= "11"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO X F 00
		
		S <= "010"; --Operación: Not A
		A <= "00"; B <= "XX"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "01"; B <= "XX"; CI <= 'X';wait for 10 ms;	--CO X F 10
		A <= "10"; B <= "XX"; CI <= 'X';wait for 10 ms;	--CO X F 01
		A <= "11"; B <= "XX"; CI <= 'X';wait for 10 ms;	--CO X F 00
		
		S <= "011"; --Operación: A Xor B
		A <= "00"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO X F 00
		A <= "00"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO X F 01
		A <= "00"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO X F 10
		A <= "00"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "01"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO X F 01
		A <= "01"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO X F 00
		A <= "01"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "01"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO X F 10
		A <= "10"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO X F 10
		A <= "10"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "10"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO X F 00
		A <= "10"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO X F 01
		A <= "11"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO X F 11
		A <= "11"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO X F 10
		A <= "11"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO X F 01
		A <= "11"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO X F 00
		
		S <= "100"; --Operación: A + B + CO
		A <= "00"; B <= "00"; CI <= '0';wait for 10 ms;	--CO 0 F 00
		A <= "00"; B <= "01"; CI <= '0';wait for 10 ms;	--CO 0 F 01
		A <= "00"; B <= "10"; CI <= '0';wait for 10 ms;	--CO 0 F 10
		A <= "00"; B <= "11"; CI <= '0';wait for 10 ms;	--CO 0 F 11
		A <= "01"; B <= "00"; CI <= '0';wait for 10 ms;	--CO 0 F 01
		A <= "01"; B <= "01"; CI <= '0';wait for 10 ms;	--CO 0 F 10
		A <= "01"; B <= "10"; CI <= '0';wait for 10 ms;	--CO 0 F 11
		A <= "01"; B <= "11"; CI <= '0';wait for 10 ms;	--CO 1 F 00
		A <= "10"; B <= "00"; CI <= '0';wait for 10 ms;	--CO 0 F 10
		A <= "10"; B <= "01"; CI <= '0';wait for 10 ms;	--CO 0 F 11
		A <= "10"; B <= "10"; CI <= '0';wait for 10 ms;	--CO 1 F 00
		A <= "10"; B <= "11"; CI <= '0';wait for 10 ms;	--CO 1 F 01
		A <= "11"; B <= "00"; CI <= '0';wait for 10 ms;	--CO 0 F 11
		A <= "11"; B <= "01"; CI <= '0';wait for 10 ms;	--CO 1 F 00
		A <= "11"; B <= "10"; CI <= '0';wait for 10 ms;	--CO 1 F 01
		A <= "11"; B <= "11"; CI <= '0';wait for 10 ms;	--CO 1 F 10
		A <= "00"; B <= "00"; CI <= '1';wait for 10 ms;	--CO 0 F 01
		A <= "00"; B <= "01"; CI <= '1';wait for 10 ms;	--CO 0 F 10
		A <= "00"; B <= "10"; CI <= '1';wait for 10 ms;	--CO 0 F 11
		A <= "00"; B <= "11"; CI <= '1';wait for 10 ms;	--CO 1 F 00
		A <= "01"; B <= "00"; CI <= '1';wait for 10 ms;	--CO 0 F 10
		A <= "01"; B <= "01"; CI <= '1';wait for 10 ms;	--CO 0 F 11
		A <= "01"; B <= "10"; CI <= '1';wait for 10 ms;	--CO 1 F 00
		A <= "01"; B <= "11"; CI <= '1';wait for 10 ms;	--CO 1 F 01
		A <= "10"; B <= "00"; CI <= '1';wait for 10 ms;	--CO 0 F 11
		A <= "10"; B <= "01"; CI <= '1';wait for 10 ms;	--CO 1 F 00
		A <= "10"; B <= "10"; CI <= '1';wait for 10 ms;	--CO 1 F 01
		A <= "10"; B <= "11"; CI <= '1';wait for 10 ms;	--CO 1 F 10
		A <= "11"; B <= "00"; CI <= '1';wait for 10 ms;	--CO 1 F 00
		A <= "11"; B <= "01"; CI <= '1';wait for 10 ms;	--CO 1 F 01
		A <= "11"; B <= "10"; CI <= '1';wait for 10 ms;	--CO 1 F 10
		A <= "11"; B <= "11"; CI <= '1';wait for 10 ms;	--CO 1 F 11
		
		S <= "101"; --Operación: A - B
		A <= "00"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO 0 F 00
		A <= "00"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO 1 F 11
		A <= "00"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO 1 F 10
		A <= "00"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO 1 F 01
		A <= "01"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO 0 F 01
		A <= "01"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO 0 F 00
		A <= "01"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO 1 F 11
		A <= "01"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO 1 F 10
		A <= "10"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO 0 F 10
		A <= "10"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO 0 F 01
		A <= "10"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO 0 F 00
		A <= "10"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO 1 F 11
		A <= "11"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO 0 F 11
		A <= "11"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO 0 F 10
		A <= "11"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO 0 F 01
		A <= "11"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO 0 F 00
		
		S <= "110"; --Operación: A + 1 + CO
		A <= "00"; B <= "XX"; CI <= '0';wait for 10 ms;	--CO 0 F 01
		A <= "01"; B <= "XX"; CI <= '0';wait for 10 ms;	--CO 0 F 10
		A <= "10"; B <= "XX"; CI <= '0';wait for 10 ms;	--CO 0 F 11
		A <= "11"; B <= "XX"; CI <= '0';wait for 10 ms;	--CO 1 F 00
		A <= "00"; B <= "XX"; CI <= '1';wait for 10 ms;	--CO 0 F 10
		A <= "01"; B <= "XX"; CI <= '1';wait for 10 ms;	--CO 0 F 11
		A <= "10"; B <= "XX"; CI <= '1';wait for 10 ms;	--CO 1 F 00
		A <= "11"; B <= "XX"; CI <= '1';wait for 10 ms;	--CO 1 F 01
		
		S <= "111"; --Operación: B - 1
		A <= "XX"; B <= "00"; CI <= 'X';wait for 10 ms;	--CO 1 F 11
		A <= "XX"; B <= "01"; CI <= 'X';wait for 10 ms;	--CO 0 F 00
		A <= "XX"; B <= "10"; CI <= 'X';wait for 10 ms;	--CO 0 F 01
		A <= "XX"; B <= "11"; CI <= 'X';wait for 10 ms;	--CO 0 F 10

      wait;
   end process;

END;
