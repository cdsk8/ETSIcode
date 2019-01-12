LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Practica7CircuitoTest IS
END Practica7CircuitoTest;
 
ARCHITECTURE behavior OF Practica7CircuitoTest IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Practica7Circuito
    PORT(
         E_inicial : IN  std_logic;
         RS : IN  std_logic;
         CK : IN  std_logic;
         S : OUT  std_logic;
         Q : OUT  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal E_inicial : std_logic := '0';
   signal RS : std_logic := '0';
   signal CK : std_logic := '0';

 	--Outputs
   signal S : std_logic;
   signal Q : std_logic_vector(2 downto 0);
   -- No clocks detected in port list. Replace CK below with 
   -- appropriate port name 
 
   constant CK_period : time := 20 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Practica7Circuito PORT MAP (
          E_inicial => E_inicial,
          RS => RS,
          CK => CK,
          S => S,
          Q => Q
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
		E_inicial<='0';RS<='0'; Wait for 20 ns;
		RS<='1'; Wait for 20 ns;
		RS<='0';
		
		
		--Intento de encendido fallido en POS 1, camino L.
		E_inicial<='0'; --GOTO L1
		E_inicial<='1'; Wait for 20 ns; --GOTO RS
		
		--Intento de encendido fallido en POS 2, camino L.
		E_inicial<='0'; Wait for 20 ns; --GOTO L1
		E_inicial<='0'; Wait for 20 ns; --GOTO L2
		E_inicial<='1'; Wait for 20 ns; --GOTO RS
		
		--Intento de encendido correcto, camino L.
		E_inicial<='0'; Wait for 20 ns; --GOTO L1
		E_inicial<='0'; Wait for 20 ns; --GOTO L2
		E_inicial<='0'; Wait for 20 ns; --GOTO LF
		E_inicial<='1'; Wait for 20 ns; --GOTO RS
		
		--Intento de encendido fallido en POS 1, camino H.
		E_inicial<='1'; Wait for 20 ns; --GOTO H1
		E_inicial<='0'; Wait for 20 ns; --GOTO RS
		
		--Intento de encendido fallido en POS 2, camino H.
		E_inicial<='1'; Wait for 20 ns; --GOTO H1
		E_inicial<='1'; Wait for 20 ns; --GOTO H2
		E_inicial<='0'; Wait for 20 ns; --GOTO RS
		
		--Intento de encendido correcto, camino H.
		E_inicial<='1'; Wait for 20 ns; --GOTO H1
		E_inicial<='1'; Wait for 20 ns; --GOTO H2
		E_inicial<='1'; Wait for 20 ns; --GOTO HF
		E_inicial<='0'; Wait for 20 ns; --GOTO RS
      wait;wait;
		
   end process;

END;
