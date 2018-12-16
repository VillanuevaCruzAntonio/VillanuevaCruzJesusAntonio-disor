module TGrupal
    def initTGrupal
        $textoEntrada = ""
        $numIntegrantes = 0
    end

    def setGrupo(value)
        $numIntegrantes = value.to_i
    end

    def setTextoAgrupado(value)
        $textoEntrada = value
    end
    
    def obtenerGrupo
        $numIntegrantes
    end

    def getTextoAgrupado
        $textoEntrada
    end

    def cifrado()
        $palabras = $textoEntrada.split('')
        $textoIntegrantes = ""
        $textoCifrado = ""
        $limitador = 0
        if $numIntegrantes == 1
            return obtenerTranspuesta
        else
            for indice in(1..$palabras.length)
                if $numIntegrantes != 0 and indice % $numIntegrantes == 0
                    $textoIntegrantes = $textoIntegrantes + $palabras[indice-1]
                    $textoCifrado = $textoCifrado + $textoIntegrantes.reverse
                    $textoIntegrantes = ""
                    $limitador = 0
                else
                    $textoIntegrantes = $textoIntegrantes +""+ $palabras[indice-1].to_s
                    $limitador = 1
                end
            end
            
            if $limitador == 0
                return $textoCifrado
            else
                return $textoCifrado + $textoIntegrantes
            end
        end
      end

end
