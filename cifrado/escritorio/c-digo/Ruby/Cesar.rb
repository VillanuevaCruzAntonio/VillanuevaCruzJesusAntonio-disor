class Cesar
    @Texto
    def initialize(textoEntrada,salto)
        @Texto=cifrar(textoEntrada,salto)
    end 

    def cifrar(texto,numSalto)
        salida=""
        texto.length.times do |index| 
            if /[a-z]/.match(texto[index])
              letra = texto[index].ord + numSalto
              if letra > "z".ord
                salida.concat((letra - 26).chr)
              else
                salida.concat(letra.chr)
              end
            elsif /[A-Z]/.match(texto[index])
              letra = texto[index].ord + numSalto
              if letra > "Z".ord
                salida.concat((letra - 26).chr)
              else
                salida.concat(letra.chr)
              end
            else
                salida.concat(texto[index])
            end
          end
          return salida
    end


    def getMensaje()
        @Texto
    end
end
