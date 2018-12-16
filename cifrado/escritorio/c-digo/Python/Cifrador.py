from Texto.TextoPlano import TextoPlano
from Cifrados.cifradoCesar import CifradoCesar
from Cifrados.cifradoTInversa import CifradoTInversa
from Cifrados.cifradoTGrupo import CifradoTGrupo

class Cifrador:

    def __init__(self):
        self.textoEntrada = TextoPlano("")
        self.cCesar = CifradoCesar("", 3)
        self.cTG = CifradoTGrupo("", 3)
        self.cTI = CifradoTInversa("")
        self.array = ""

    def datoExternoTXT(self, nuevo ,val ,val2):
        self.array = nuevo
        estText = TextoPlano(nuevo)
        self.textoEntrada.difDimensiones(nuevo)

        self.evenCifradoTInversa(estText,nuevo)
        self.evenCifradoCesar(nuevo ,val)
        self.evenCifradoTGrupo(nuevo ,val2)

        self.textoEntrada.refresh(nuevo)

    def evenCifradoTInversa(self ,estText,txt):
        if self.textoEntrada.backOne(estText):
            self.cTI.back()
        elif self.textoEntrada.step(estText):
            self.cTI.front(self.textoEntrada.textoDiferen)
        else:
            self.cTI.cifra(txt)

    def evenCifradoCesar(self ,txt,salto):
        self.cCesar.cifrar(txt,salto)

    def evenCifradoTGrupo(self ,txt,group):
        self.cTG.cifrar(txt,group)
