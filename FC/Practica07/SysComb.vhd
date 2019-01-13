library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.std_logic_arith.ALL;
use IEEE.numeric_std.ALL;

entity SysComb is
	Port(E, RS, CK:in STD_LOGIC;S:out STD_LOGIC; Q:out STD_LOGIC_VECTOR(2 downto 0));
end SysComb;

architecture Behavioral of SysComb is
	Subtype estados is STD_LOGIC_VECTOR(2 downto 0);
	Constant RESET : estados := "000";
	Constant L1 : estados := "001";
	Constant L2 : estados := "010";
	Constant LF : estados := "011";
	Constant H1 : estados := "101";
	Constant H2 : estados := "110";
	Constant HF : estados := "111";
	Signal estado : estados;
begin
	process(RS, CK, E, estado)
	begin
		If RS='1' Then estado <= RESET; Else
			If CK'event and CK='1' Then
				If estado = RESET Then	If E = '1' Then estado <= H1; Else estado <= L1; End If;
				ElsIf estado = H1 Then	If E = '1' Then estado <= H2; Else estado <= RESET; End If;
				ElsIf estado = H2 Then	If E = '1' Then estado <= HF; Else estado <= RESET; End If;
				ElsIf estado = HF Then	If E = '0' Then estado <= RESET; End If;
				ElsIf estado = L1 Then	If E = '0' Then estado <= L2; Else estado <= RESET; End If;
				ElsIf estado = L2 Then	If E = '0' Then estado <= LF; Else estado <= RESET; End If;
				ElsIf estado = LF Then	If E = '1' Then estado <= RESET; End If;
				End If;
			End If;
		End If;
	end process;
	
	Q <= estado;
	S <= '1' when estado = HF or estado = LF else '0';
end Behavioral;