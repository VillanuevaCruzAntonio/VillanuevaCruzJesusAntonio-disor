class TextoPlano:
    def __init__(self ,textEntrada):
        self.textoInit = textEntrada
        self.arrayNext = ""
        self.arrayDown = ""

    def __str__(self):
        return self.textoInit

    def __eq__(self, other):
        return self.textoInit == other.textoInit

    def __ge__(self, other):
        return len(self.textoInit) >= len(other.textoInit)

    def __lt__(self, other):
        return len(self.textoInit) < len(other.textoInit)

    def backOne(self ,textoUpdate):
        return self.arrayDown == textoUpdate.textoInit

    def step(self ,textoUpdate):
        return (len(self.textoInit) == len(textoUpdate.textoInit)-1)

    def difDimensiones(self, textoUpdate):
        if self.backOne( TextoPlano(textoUpdate) ):
            self.arrayNext = self.textoInit[:-1] 
            if len(self.textoInit) > 0 
	      else ""
        else:
            self.arrayNext = textoUpdate[-1] 
            if len(textoUpdate)>0 
	      else ""

    def refresh(self ,textoUpdate):
        self.arrayDown = self.textoInit
        self.textoInit = textoUpdate
