library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Practica7 is
	Port(	E, Reset, CLK_50MHZ, CLK_CR:in STD_LOGIC;
			S:out STD_LOGIC;
			Q:out STD_LOGIC_VECTOR(2 downto 0));
end Practica7 ;

architecture Behavioral of Practica7 is
	signal CLK_SR : std_logic;
	
	component Antirrebotes
		PORT (CLK_50MHZ, E: IN STD_LOGIC; S: OUT STD_LOGIC);
	end component;
	component SysComb
		Port(E, RS, CK:in STD_LOGIC;S:out STD_LOGIC; Q:out STD_LOGIC_VECTOR(2 downto 0));
	end component;
begin
	AR: Antirrebotes PORT MAP (
		E => CLK_CR,
		S => CLK_SR,
		CLK_50MHZ => CLK_50MHZ
	);
	circuito: SysComb PORT MAP (
		E => E,
		RS => Reset,
		CK => CLK_SR,
		S => S,
		Q => Q
	);
end Behavioral;