class Texto
    $textoEntrada = []

    def initialize()
        (0..254).each do |x|
            if( x.chr(Encoding::UTF_8).gsub(/[^[:print:]]/i, '') != "" )
              $textoEntrada.push(x.chr(Encoding::UTF_8) ) 
            end
        end
    end

    def getLetra(posicion)
        if posicion > $textoEntrada.length
            return $textoEntrada[(posicion-$textoEntrada.length)-1]
        elsif posicion < 0
            return $textoEntrada[(posicion+$textoEntrada.length)+1]
        else
            return $textoEntrada[posicion]
        end
    end 

    def obtenerPosicion(letra)
        if $textoEntrada.include?(letra)
            return $textoEntrada.index(letra)
        else
            return -1
        end
    end

    def getDimensionTamanio()
        return $textoEntrada.length
    end 

    def getText()
        return $textoEntrada.length
    end
end
