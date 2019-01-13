LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Practica7Test IS
END Practica7Test;
 
ARCHITECTURE behavior OF Practica7Test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Practica7
    PORT(
         E : IN  std_logic;
         Reset : IN  std_logic;
         CLK_50MHZ : IN  std_logic;
         CLK_CR : IN  std_logic;
         S : OUT  std_logic;
         Q : OUT  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal E : std_logic := '0';
   signal Reset : std_logic := '0';
   signal CLK_50MHZ : std_logic := '0';
   signal CLK_CR : std_logic := '0';

 	--Outputs
   signal S : std_logic;
   signal Q : std_logic_vector(2 downto 0);

   -- Clock period definitions
   constant CLK_50MHZ_period : time := 20 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Practica7 PORT MAP (
          E => E,
          Reset => Reset,
          CLK_50MHZ => CLK_50MHZ,
          CLK_CR => CLK_CR,
          S => S,
          Q => Q
        );

   -- Clock process definitions
   CLK_50MHZ_process :process
   begin
		CLK_50MHZ <= '0';
		wait for CLK_50MHZ_period/2;
		CLK_50MHZ <= '1';
		wait for CLK_50MHZ_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CLK_50MHZ_period*10; -- Ejecutar durante 5 us

      -- Reseteo
		E<='0';Reset<='0';	Wait for 100 ns;
		E<='0';Reset<='1';	Wait for 100 ns;
		E<='0';Reset<='0';	Wait for 100 ns;
		
		-- Llegar hasta L1
		E<='0';CLK_CR<='0';	Wait for 100 ns;
		E<='0';CLK_CR<='1';	Wait for 100 ns; -- L1
		E<='1';CLK_CR<='0';	Wait for 100 ns;
		E<='1';CLK_CR<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='0';CLK_CR<='0';	Wait for 100 ns;
		E<='0';CLK_CR<='1';	Wait for 100 ns; -- L1
		E<='0';CLK_CR<='0';	Wait for 100 ns;
		E<='0';CLK_CR<='1';	Wait for 100 ns; -- L2
		E<='1';CLK_CR<='0';	Wait for 100 ns;
		E<='1';CLK_CR<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='0';CLK_CR<='0';	Wait for 100 ns;
		E<='0';CLK_CR<='1';	Wait for 100 ns; -- L1
		E<='0';CLK_CR<='0';	Wait for 100 ns;
		E<='0';CLK_CR<='1';	Wait for 100 ns; -- L2
		E<='0';CLK_CR<='0';	Wait for 100 ns;
		E<='0';CLK_CR<='1';	Wait for 100 ns; -- LF y S
		E<='1';CLK_CR<='0';	Wait for 100 ns;
		E<='1';CLK_CR<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='1';CLK_CR<='0';	Wait for 100 ns;
		E<='1';CLK_CR<='1';	Wait for 100 ns; -- H1
		E<='0';CLK_CR<='0';	Wait for 100 ns;
		E<='0';CLK_CR<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='1';CLK_CR<='0';	Wait for 100 ns;
		E<='1';CLK_CR<='1';	Wait for 100 ns; -- H1
		E<='1';CLK_CR<='0';	Wait for 100 ns;
		E<='1';CLK_CR<='1';	Wait for 100 ns; -- H2
		E<='0';CLK_CR<='0';	Wait for 100 ns;
		E<='0';CLK_CR<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='1';CLK_CR<='0';	Wait for 100 ns;
		E<='1';CLK_CR<='1';	Wait for 100 ns; -- H1
		E<='1';CLK_CR<='0';	Wait for 100 ns;
		E<='1';CLK_CR<='1';	Wait for 100 ns; -- H2
		E<='1';CLK_CR<='0';	Wait for 100 ns;
		E<='1';CLK_CR<='1';	Wait for 100 ns; -- HF y S
		E<='0';CLK_CR<='0';	Wait for 100 ns;
		E<='0';CLK_CR<='1';	Wait for 100 ns; -- RESET

      wait;wait;
   end process;

END;
