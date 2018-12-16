module Cifrador
    def init_cifrador(texto)
            @textEntrada = texto
    end

    def remplazaLetra(salto,letra)
        posicion = @textEntrada.obtenerPosicion(letra)
        if posicion > 0
            return @textEntrada.obtenerCaracter(posicion+salto)
        else
            return letra
        end
    end

    def cifrarTexto(salto,texto)
        textoSalida = ""
        texto.chars.each{
            |letra| textoSalida = textoSalida + remplazaLetra(salto,letra)
        }
        return textoSalida
    end
end
