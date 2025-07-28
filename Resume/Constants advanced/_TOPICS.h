#pragma once
/*
🧠 Avançado / Menos falado:
Tema											Explicação
✅ Constantes globais const e static const		const tem internal linkage, ou seja, cada TU (translation unit) cria uma cópia. extern const pode ser usado para compartilhar.
✅ mutable vs const								mutable permite modificar membros mesmo em métodos const. Ideal para cache ou contadores.
✅ const_cast									Remove o const temporariamente. Deve ser usado com cuidado extremo.
✅ const com arrays e strings					Arrays de char são const char* quando literais. Ex: const char* nome = "texto";
✅ Constantes em enum class						Úteis em switch, constexpr e como flags.
✅ const com lambdas							[=]() const {} torna a lambda "const" (não modifica as capturas). Útil em classes e chamadas múltiplas.
✅ const em parâmetros de template				Já vimos template <const int N>; também pode haver uso com constexpr.
*/