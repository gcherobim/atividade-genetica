rm(list = ls())

tam_fragmentos = c(300, 3000, 30000)
tam_posicao = c(100, 1000, 10000)
tam_genoma = c(10000, 100000, 1000000)

tempo_fragmentos = c(1.3457, 12.8604, 128.7120)
tempo_posicao = c(127.9803, 128.4289, 128.7120)
tempo_genoma = c(2.9453, 27.1118, 128.7120)

plot(tam_fragmentos, tempo_fragmentos, col = "red", main = "Fragmentos", xlab = "Tamanho", ylab = "Tempo")
plot(log(tam_fragmentos), log(tempo_fragmentos), col = "red", main = "Fragmentos", xlab = "Tamanho", ylab = "Tempo")
fit_fragmetnos = lm(formula = log(tempo_fragmentos) ~ log(tam_fragmentos))
summary(fit_fragmetnos)
abline(fit_fragmetnos, col = "blue")

plot(tam_posicao, tempo_posicao)
plot(log(tam_posicao), log(tempo_posicao), col = "red", main = "Posição", xlab = "Tamanho", ylab = "Tempo")
fit_posicao = lm(formula = log(tempo_posicao) ~ log(tam_posicao))
summary(fit_posicao)
abline(fit_posicao, col = "blue")

plot(tam_genoma, tempo_genoma)
plot(log(tam_genoma), log(tempo_genoma), col = "red", main = "Genoma", xlab = "Tamanho", ylab = "Tempo")
fit_genoma = lm(formula = log(tempo_genoma) ~ log(tam_genoma))
summary(fit_genoma)
abline(fit_genoma, col = "blue")

tempo_ordena = c(0.000087, 0.000568, 0.005927)
plot(tam_fragmentos, tempo_ordena, col = "red", main = "Fragmentos", xlab = "Tamanho", ylab = "Tempo")
plot(log(tam_fragmentos), log(tempo_ordena), col = "red", main = "", xlab = "Tamanho", ylab = "Tempo")
fit_ordena = lm(formula = log(tempo_ordena) ~ log(tam_fragmentos))
summary(fit_ordena)
abline(fit_ordena, col = "blue")
