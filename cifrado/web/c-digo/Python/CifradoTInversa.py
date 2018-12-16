class cifradoTInversa:

    def __init__(self , textoEntrada):
        self.txt = textoEntrada
        self.textoSalida = ""
        self.vacio = ""

    def cifra(self,txtnew):
        self.vacio = self.textoSalida
        self.textoSalida = txtnew[::-1]
        return self.textoSalida

    def front(self ,letra):
        self.vacio = self.textoSalida
        self.textoSalida = letra +self.textoSalida

    def back(self):
        aux = self.vacio
        self.vacio = self.textoSalida
        self.textoSalida = aux

    def __str__(self):
return self.textoSalida
