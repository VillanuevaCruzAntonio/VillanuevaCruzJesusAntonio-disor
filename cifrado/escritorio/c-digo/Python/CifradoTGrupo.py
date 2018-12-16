class cifradoTGrupo:

    def __init__(self , Texto, salto):
        self.textoEntrada = Texto
        self.grup = salto
        self.vacio = ""
        self.cifradoAnterior = ""
        
    def cifra(self,txtnew):
        self.vacio = self.textoSalida
        self.textoSalida = txtnew[::-1]
        return self.textoSalida

    def cifrarGrupal(self,textoEntrada,group):
        if group <2:
            self.vacio = textoEntrada
            return
        if group >= len(textoEntrada):
            self.vacio = cifra(textoEntrada)
            return

        lis = zip(*([iter(textoEntrada)]*group))
        part = [ cifra("".join(i)) for i in lis  ]
        if len(textoEntrada)%group != 0:
            self.vacio = "".join(part) + textoEntrada[-(len(textoEntrada)%group):]
        else:
            self.vacio = "".join(part)
