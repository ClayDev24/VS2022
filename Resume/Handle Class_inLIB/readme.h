
/*
Por que usar Handle Class em bibliotecas ?
	-Quando você distribui uma biblioteca, você quer esconder :
		-Os detalhes internos da implementação;
		-Mudanças futuras na implementação que não quebrem a interface pública;
		-Estruturas de terceiros que o cliente não precisa conhecer.
*/

/*Benefícios em contexto de biblioteca:
	✅ Você pode alterar a implementação internamente (Pessoa::Impl) sem recompilar o cliente.
	✅ O cliente só precisa da pasta include/ para usar a lib.
	✅ Você pode evitar dependências pesadas no cabeçalho (como <iostream>, <vector> etc).
*/