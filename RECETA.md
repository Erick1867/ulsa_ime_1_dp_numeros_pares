## Receta: Guardar los números pares
1. Mostrar mensaje de bienvenida.
2. `totalPares ← 0`
   `CANTIDAD ← 5`
   3. `contador ← 0`
4. MIENTRAS `contador < CANTIDAD` HACER
   `numero ← leerEntero("Ingresa un numero")`
   SI `numero % 2 == 0` ENTONCES
   `pares[totalPares] ← numero`
   `totalPares ← totalPares + 1`
   FIN SI
   `contador ← contador + 1`
   FIN MIENTRAS
5. Mostrar `"Pares encontrados: "` y `totalPares`.
6. `i ← 0`
7. MIENTRAS `i < totalPares` HACER
   Mostrar `pares[i]`
   `i ← i + 1`
   FIN MIENTRAS
