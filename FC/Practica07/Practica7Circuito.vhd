library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Practica7Circuito is
	Port(	E, RS, CK:in STD_LOGIC;
			S:out STD_LOGIC;
			Q:out STD_LOGIC_VECTOR(2 downto 0));
end Practica7Circuito;

architecture Behavioral of Practica7Circuito is
	signal E_estable : std_logic;
	
	component Practica7
		Port(E, RS, CK:in STD_LOGIC;S:out STD_LOGIC; Q:out STD_LOGIC_VECTOR(2 downto 0));
	end component;
	component ANTIRREBOTES
		PORT (CLK_50MHZ, E: IN STD_LOGIC; S: OUT STD_LOGIC);
	end component;
begin
	AR: ANTIRREBOTES PORT MAP (
		E => E,
		S => E_estable,
		CLK_50MHZ => CK
	);
	circuito: Practica7 PORT MAP (
		E => E_estable,
		RS => RS,
		CK => CK,
		S => S,
		Q => Q
	);
end Behavioral;

