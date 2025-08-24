#pragma once
/*
2. Quando escolher qual algoritmo?
Poucos elementos → Insertion Sort ou Bubble Sort.
	-Grandes volumes → Merge Sort ou Quick Sort.
	-Inteiros pequenos e conhecidos → Counting Sort ou Radix Sort.
	-Precisa ser estável (manter a ordem de elementos iguais)? →
		Prefira Merge, Counting, Bubble, Insertion.
*/
/*
3. Ordenação Estável vs Instável
	-Estável: Elementos iguais mantêm a posição relativa original.
		Ex: Se dois objetos com mesmo "peso" aparecem, eles continuam na mesma ordem.
	-Instável: A ordem dos elementos iguais pode mudar após a ordenação.
*/
/*
4. Ordenação Parcial
	-Às vezes, não precisa ordenar tudo!
	Ex: "Quero apenas os 10 maiores elementos."
		-Usa partial_sort ou nth_element em C++.
		-Mais rápido que ordenar todo o vetor.
*/
/*
6. Sorting Interno vs Externo
	-Interno: Todo o vetor cabe na memória RAM (casos normais).
	-Externo: Dados gigantescos (Ex: bancos de dados, Big Data)→
		técnicas especiais, como "External Merge Sort".
*/