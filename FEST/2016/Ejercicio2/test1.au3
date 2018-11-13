;Const $ss = 10, $mm = 0, $hh = 0, $dd = 0
;Const $ss = 40, $mm = 0, $hh = 0, $dd = 0
;Const $ss = 20, $mm = 14, $hh = 0, $dd = 0
Const $ss = 0, $mm = 0, $hh = 0, $dd = 1
Const $tiempo = ($dd*24*3600)+($hh*3600)+($mm*60)+$ss

ConsoleWrite($tiempo&@CRLF)
$consumicion = 0
Local $h = 0, $m = 0, $s = 0
For $i = 0 To $tiempo-1
   $consumicion += getConsumo($s) + getConsumo($m) + getConsumo($h)
   $s += 1
   If $s = 60 Then
	  $s = 0
	  $m += 1
	  If $m = 60 Then
		 $m = 0
		 $h += 1
		 If $h = 24 Then
			$h = 0
		 EndIf
	  EndIf
   EndIf
Next

;ConsoleWrite("Se consume: "&$consumicion&@CRLF)
ConsoleWrite("Se consume: "&($consumicion*365)&@CRLF)

Func getConsumo($n)
   If $n < 10 Then  $n = "0"&$n
   $nn = StringSplit($n,"")
   $total = 0
   For $i = 1 To $nn[0]
	  Switch($nn[$i])
	  case 0:
		 $total += 6
	  case 1:
		 $total += 2
	  case 2:
		 $total += 5
	  case 3:
		 $total += 5
	  case 4:
		 $total += 4
	  case 5:
		 $total += 5
	  case 6:
		 $total += 6
	  case 7:
		 $total += 3
	  case 8:
		 $total += 7
	  case 9:
		 $total += 6
	  EndSwitch
   Next
   return $total
EndFunc