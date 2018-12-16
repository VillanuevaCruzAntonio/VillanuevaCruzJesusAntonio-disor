class TInversa
    @Texto
    def initialize(textoEntrada)
        @Texto=cifradoTInvesa(textoEntrada)
    end

    def cifradoTInvesa(textoEntrada)
        textoSalida=""
        indice=0
        while indice<textoEntrada.length
            textoSalida=textoEntrada[indice]+textoSalida
            indice+=1
        end
        return textoSalida
    end

    def getMensaje
        return @Texto
    end
    
end
