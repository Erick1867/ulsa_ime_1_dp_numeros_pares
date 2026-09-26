# Práctica 2: Guardar los números pares

## 1. Descripción del problema (Fase 1)

El programa pide al usuario 5 números enteros y guarda solamente los números pares en un arreglo. Los números impares se descartan y al final se muestra cuántos pares se encontraron y cuáles son. Esto puede servir para separar datos que cumplen con una condición, como piezas que pasan un control de calidad.

## 2. Entradas y salidas (Fase 1)

**Entradas:**

1. **5 números enteros que escribe el usuario.**

**Salidas:**

1. **La cantidad de números pares encontrados.**
2. **Los números pares guardados en el arreglo.**

## 3. Restricciones e invariante (Fase 1 y 2)

**Restricciones** (¿qué debe cumplirse?):

* **El programa debe pedir exactamente 5 números enteros.**
* **Solo los números pares se deben guardar en el arreglo y los impares se deben descartar.**

**Tamaño del arreglo y por qué** (piensa en el peor caso):

**El arreglo debe tener tamaño 5 porque en el peor caso los 5 números ingresados pueden ser pares.**

**¿El 0 y los negativos son pares? ¿Por qué?**

**Sí. El 0 es par y los números negativos también pueden ser pares. Por ejemplo, -4 es par porque al dividirlo entre 2 no deja residuo.**

**Invariante** (¿qué es verdad después de cada vuelta del ciclo?):

**Después de cada vuelta, `totalPares` representa la cantidad de números pares que se han encontrado y también indica la siguiente posición libre del arreglo.**

## 4. Casos resueltos a mano (Fase 1)

| Caso | Números         | Pares guardados | Posición de cada par                             |
| ---- | --------------- | --------------- | ------------------------------------------------ |
| 1    | 3, 8, 5, 2, 7   | 8, 2            | `pares[0] = 8`, `pares[1] = 2`                   |
| 2    | 1, 4, 6, 9, 11  | 4, 6            | `pares[0] = 4`, `pares[1] = 6`                   |
| 3    | 2, 5, 10, 7, 12 | 2, 10, 12       | `pares[0] = 2`, `pares[1] = 10`, `pares[2] = 12` |

## 5. Receta en pseudocódigo (Fase 2)

**¿Probé mi receta a mano con un caso?** Sí

**¿Tuve que corregirla?** No, la receta funcionó al probarla con el caso 3, 8, 5, 2, 7.

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o numeros_pares

./numeros_pares
```

## 7. Ejemplo de ejecución (Fase 3)

```text
Guardar los numeros pares de 5 numeros
Escribe un numero: 3
Escribe un numero: 8
Escribe un numero: 5
Escribe un numero: 2
Escribe un numero: 7
Pares encontrados: 2
8
2
```

## 8. Experimentos (Fase 3)

**Experimento A: ¿qué apareció al imprimir las 5 posiciones del arreglo? ¿Por qué?**

Al imprimir las 5 posiciones aparecieron los pares guardados y también valores que no corresponden a los datos ingresados. Esto pasa porque algunas posiciones del arreglo quedaron sin llenar y no tienen un valor válido. Por eso después se debe recorrer solamente hasta `totalPares`.

**Experimento B: ¿qué pasó al usar la variable del ciclo como posición del arreglo? ¿Por qué?**

Los pares se guardaron en posiciones incorrectas. Esto pasa porque la variable del ciclo indica qué número de los 5 se está procesando, pero no cuántos pares se han guardado. La posición correcta la indica `totalPares`.

## 9. Tabla de pruebas (Fase 4)

| Caso                 | Números          | Esperado           | Obtenido                 | ¿Pasó? |
| -------------------- | ---------------- | ------------------ | ------------------------ | ------ |
| Mezcla               | 1, 2, 3, 4, 5    | 2 pares: 2, 4      | 2 pares: 2, 4            | Sí     |
| Posiciones distintas | 3, 8, 5, 2, 7    | 2 pares: 8, 2      | 2 pares: 8, 2            | Sí     |
| Todos pares          | 2, 4, 6, 8, 10   | 5 pares            | 5 pares: 2, 4, 6, 8, 10  | Sí     |
| Todos impares        | 1, 3, 5, 7, 9    | 0 pares            | 0 pares                  | Sí     |
| Con cero y negativos | 0, -3, -4, 7, 1  | 2 pares: 0, -4     | 2 pares: 0, -4           | Sí     |
| Entrada inválida     | `hola` o `3.5`   | vuelve a pedir     | Vuelve a pedir el número | Sí     |
| Caso propio 1        | 6, 7, 12, 15, 20 | 3 pares: 6, 12, 20 | 3 pares: 6, 12, 20       | Sí     |
| Caso propio 2        | -2, -5, 0, 9, 14 | 3 pares: -2, 0, 14 | 3 pares: -2, 0, 14       | Sí     |

## 10. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar?                                                  | ¿Qué cambié?                                       | ¿Funcionó? |
| - | -------------------------------------------------------------------------------- | -------------------------------------------------- | ---------- |
| 1 | Al principio se podían recorrer las 5 posiciones aunque no todas tuvieran datos. | Cambié el recorrido para usar `totalPares`.        | Sí         |
| 2 | La posición del arreglo podía confundirse con la variable del ciclo.             | Usé `totalPares` como la siguiente posición libre. | Sí         |

**Reto elegido (opcional):** Mostrar un mensaje cuando no se encuentren números pares.

## 11. Dudas para el profesor (Fase 3)

| Duda                                                                                 | Lo que ya intenté                                       |
| ------------------------------------------------------------------------------------ | ------------------------------------------------------- |
| ¿Por qué `totalPares` también funciona como la siguiente posición libre del arreglo? | Revisé cómo aumenta después de guardar cada número par. |

## 12. Reflexión final

**¿Qué aprendí con esta práctica?**

Aprendí a usar arreglos para guardar datos, a revisar si un número es par usando el operador `%` y a usar una variable para saber cuántos datos se han guardado. También aprendí que no es lo mismo la vuelta del ciclo que la posición que ocupa un dato en el arreglo.

**Ahora que terminé, ¿qué cambiaría de mi proceso?**

Primero trataría de hacer la receta con más cuidado antes de escribir el código para evitar errores en las posiciones del arreglo.

**¿Qué fue lo más difícil y cómo lo resolví?**

Lo más difícil fue entender qué posición debía usar para guardar los números pares. Lo resolví entendiendo que `totalPares` indica cuántos pares llevo guardados y por eso también indica la siguiente posición disponible.

**¿Qué pregunta me quedó sin responder?**

Me quedó la duda de qué otras formas existen para recorrer un arreglo y guardar solamente los datos que cumplen una condición.

**¿Por qué no puedo usar la variable del ciclo para guardar en el arreglo?**

Porque la variable del ciclo cuenta todos los números que se están procesando, mientras que el arreglo solamente guarda los números pares. Por eso la posición del arreglo debe depender de `totalPares` y no de la vuelta del ciclo.

## 13. Lista de verificación antes de entregar (Fase 5)

* [ ] Llené todas las secciones (no quedan `_____`)
* [ ] Mi programa compila sin advertencias
* [ ] Probé todos los casos de la tabla
* [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
* [ ] No modifiqué `utilerias.h`
* [ ] Hice al menos 3 commits con mensajes claros
* [ ] Hice `git push` y verifiqué mi fork en GitHub
* [ ] Entregué el enlace de mi fork en Classroom
