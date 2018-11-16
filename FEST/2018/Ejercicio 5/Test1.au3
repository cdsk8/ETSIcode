#include <Array.au3>

Const $diferents[] = ["/","\"," "]

Global $n = 3
Global $k = 2
Global $cantidad = 0

iter("","")

;$n = nPicos("/\/  \","   /\ ")
;ConsoleWrite($n&@CRLF)

Func iter($txt1,$txt2)
   ConsoleWrite("MAL: "&@CRLF&$txt2&@CRLF&$txt1&@CRLF&@CRLF)
   If StringLen($txt1) = 2*$n Then
	  If nPicos($txt1,$txt2) = $k Then
		 ConsoleWrite($txt2&@CRLF&$txt1&@CRLF&@CRLF)
		 $cantidad += 1
	  EndIf
   ElseIf StringLen($txt1) < 2*$n Then
	  For $i = 0 To 2
		 For $j = 0 To 2
			iter($txt1&$diferents[$i],$txt2&$diferents[$j])
		 Next
	  Next
   EndIf
EndFunc

ConsoleWrite("Cantidad: "&$cantidad&@CRLF)

Func nPicos($txt1,$txt2)
   $semiP1 = False
   $semiP2 = False
   $c1 = StringSplit($txt1,"")
   $c2 = StringSplit($txt2,"")
   $n = 0
   For $i = 1 To $c1[0]
	  If $semiP1 Then
		 If $c1[$i] = "\" And $c2[$i] = " " Then $n += 1
		 $semiP1 = False
	  Else
		 If $c1[$i] = "/" And $c2[$i] = " " Then $semiP1 = True
	  EndIf
   Next
   For $i = 1 To $c2[0]
	  If $semiP2 Then
		 If $c2[$i] = "\" And $i+1 <= $c1[0] And $c1[$i+1] = "\" Then $n += 1
		 $semiP2 = False
	  Else
		 If $c2[$i] = "/" And $i-1 >= 0 And $c1[$i-1] = "/" Then $semiP2 = True
	  EndIf
   Next
   Return $n
EndFunc