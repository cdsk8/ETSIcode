LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY Practica5Test IS
END Practica5Test;
 
ARCHITECTURE behavior OF Practica5Test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Practica5
    PORT(
         C0 : IN  std_logic;
         C1 : IN  std_logic;
         C2 : IN  std_logic;
         C3 : IN  std_logic;
         A : OUT  std_logic;
         I : OUT  std_logic;
         J : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal C0 : std_logic := '0';
   signal C1 : std_logic := '0';
   signal C2 : std_logic := '0';
   signal C3 : std_logic := '0';

 	--Outputs
   signal A : std_logic;
   signal I : std_logic;
   signal J : std_logic;
	
		Signal entrada :  STD_LOGIC_VECTOR(3 downto 0);
	Signal entrada_int :  INTEGER range 0 to 15;
 
BEGIN
	entrada <= C3&C2&C1&C0;
	entrada_int <= CONV_INTEGER(entrada);
	-- Instantiate the Unit Under Test (UUT)
   uut: Practica5 PORT MAP (
          C0 => C0,
          C1 => C1,
          C2 => C2,
          C3 => C3,
          A => A,
          I => I,
          J => J
        );


   -- Stimulus process
   stim_proc: process
	
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

		C3 <= '0';C2 <= '0';C1 <= '0';C0 <= '0';
		Wait for 10 ms;
		C3 <= '0';C2 <= '0';C1 <= '0';C0 <= '1';
		Wait for 10 ms;
		C3 <= '0';C2 <= '0';C1 <= '1';C0 <= '0';
		Wait for 10 ms;
		C3 <= '0';C2 <= '0';C1 <= '1';C0 <= '1';
		Wait for 10 ms;
		C3 <= '0';C2 <= '1';C1 <= '0';C0 <= '0';
		Wait for 10 ms;
		C3 <= '0';C2 <= '1';C1 <= '0';C0 <= '1';
		Wait for 10 ms;
		C3 <= '0';C2 <= '1';C1 <= '1';C0 <= '0';
		Wait for 10 ms;
		C3 <= '0';C2 <= '1';C1 <= '1';C0 <= '1';
		Wait for 10 ms;
		C3 <= '1';C2 <= '0';C1 <= '0';C0 <= '0';
		Wait for 10 ms;
		C3 <= '1';C2 <= '0';C1 <= '0';C0 <= '1';
		Wait for 10 ms;
		C3 <= '1';C2 <= '0';C1 <= '1';C0 <= '0';
		Wait for 10 ms;
		C3 <= '1';C2 <= '0';C1 <= '1';C0 <= '1';
		Wait for 10 ms;
		C3 <= '1';C2 <= '1';C1 <= '0';C0 <= '0';
		Wait for 10 ms;
		C3 <= '1';C2 <= '1';C1 <= '0';C0 <= '1';
		Wait for 10 ms;
		C3 <= '1';C2 <= '1';C1 <= '1';C0 <= '0';
		Wait for 10 ms;
		C3 <= '1';C2 <= '1';C1 <= '1';C0 <= '1';
		Wait for 10 ms;

      wait;
   end process;

END;
