class CifradoCesar:

    def __init__(self , TextoEntrada, salto):
        self.text = TextoEntrada
        self.avanzaLetra = salto
        self.vacio = ""

        self.alfabeto = self.newfabeto()

    def cifrar(self ,txtnew ,value):
        self.salto = value
        self.vacio = self.text
        self.text = self.palabra(txtnew,value)
    def palabra(self,orig, cont):
        e = self.alfabeto
        return "".join(list(map(lambda x: self.reemplazaLetra(x, e, cont), list(orig))))

    def reemplazaLetra(self,letra, arreglo, avanzaLetra):
        indice = arreglo.index(letra)
        dimension = len(arreglo)
        if indice + avanzaLetra >= dimension:
            return arreglo[(indice - dimension) + avanzaLetra]
        return arreglo[indice + avanzaLetra]

    def newfabeto(self):
        return list(map(chr, range(32, 254)))
