class TGrupal
    @Texto

    def initialize(textoEntrada,numMiembros)
        @Texto=invertir(textoEntrada,numMiembros)
    end

    def invertir(textoEntrada,numMiembros)
        nuevo=textoEntrada.delete(" ")
        sobran = nuevo.length % numMiembros
        salida=nuevo.scan(/.{#{numMiembros}}/).map {|c| TInversa.new(c).getMensaje.concat(" ")}.join
        salida.concat(nuevo.chars.last(sobran).join)
    end

    def getMensaje
        return @Texto
    end
end
