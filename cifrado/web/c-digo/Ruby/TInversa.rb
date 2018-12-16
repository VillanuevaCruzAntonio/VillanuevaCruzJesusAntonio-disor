module TrnaspuestaStore
   def initTInversa
        $textoEntrada = ""
    end

    def init_transpuesta_store
        $textoTranspuesta = ""
    end

    def obtenerTextCifrado
        $textoTranspuesta
    end

        def cifrado()
        $palabras = $textoEntrada.split('')
        $textoIntegrantes = ""
        $textoCifrado = ""
	  $textoCifrado = $textoCifrado + $textoIntegrantes.reverse
          return $textoCifrado
      end
end
