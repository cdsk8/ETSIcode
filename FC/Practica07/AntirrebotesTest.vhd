LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY AntirrebotesTest IS
END AntirrebotesTest;
 
ARCHITECTURE behavior OF AntirrebotesTest IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ANTIRREBOTES
    PORT(
         CLK_50MHZ : IN  std_logic;
         E : IN  std_logic;
         S : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CK : std_logic := '0';
   signal E_inicial : std_logic := '0';

 	--Outputs
   signal E_estable : std_logic;

   -- Clock period definitions
   constant CK_period : time := 20 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ANTIRREBOTES PORT MAP (
          CLK_50MHZ => CK,
          E => E_inicial,
          S => E_estable
        );

   -- Clock process definitions
   CK_process :process
   begin
		CK <= '0';
		wait for CK_period/2;
		CK <= '1';
		wait for CK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CK_period*10;

      -- insert stimulus here
		E_inicial<='0';	wait for 10 ns;
		E_inicial<='1';	wait for 40 ns;
		
		E_inicial<='0';	wait for 5 ns;
		E_inicial<='1';	wait for 1 ns;
		E_inicial<='0';	wait for 8 ns;
		E_inicial<='1';	wait for 2 ns;
		E_inicial<='0';	wait for 2 ns;

      wait;wait;
   end process;

END;
