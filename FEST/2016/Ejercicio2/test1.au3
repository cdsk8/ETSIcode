;Const $ss = 10, $mm = 0, $hh = 0, $dd = 0
;Const $ss = 40, $mm = 0, $hh = 0, $dd = 0
;Const $ss = 20, $mm = 14, $hh = 0, $dd = 0
;Const $ss = 0, $mm = 0, $hh = 0, $dd = 1
Const $ss = 0, $mm = 0, $hh = 0, $dd = 1
Const $tiempo = ($dd*24*3600)+($hh*3600)+($mm*60)+$ss

Const $costes = [6,2,5,5,4,5,6,3,7,6]

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

ConsoleWrite("Se consume: "&$consumicion&@CRLF)
;ConsoleWrite("Se consume: "&($consumicion*365)&@CRLF)

Func getConsumo($n)
   If $n < 10 Then  $n = "0"&$n
   $nn = StringSplit($n,"")
   $total = 0
   For $i = 1 To $nn[0]
	  $total += $costes[$nn[$i]]
   Next
   return $total
EndFunc