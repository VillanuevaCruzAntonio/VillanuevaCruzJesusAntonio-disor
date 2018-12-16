<%@ Page Language="C#" Inherits="Cifrado.Default" %>
<!DOCTYPE html>
<html>
<head runat="server">
	<title>Default</title>
</head>
<body>
        <h3>Cifrados</h3>
	<form id="form1" runat="server">
        <asp:Label runat="server">Texto a Cifrar:</asp:Label>
		<asp:TextBox runat="server" id="textoPlano"/>
        <asp:Label runat="server">Desplazamiento:</asp:Label>
        <asp:TextBox runat="server" id="txtDesplazamiento"/>
        <asp:Button runat="server" id="btnConvertir" Text="Enter" OnClick="cifrarMensaje"/>

        <hr/>
        <h3>Cesar:</h3>
        <span runat="server" id="txtCifradoCesar"/>
        <hr/>
        <h3>Inverso:</h3>
        <span runat="server" id="txtCifradoInverso"/>
        <hr/>
        <h3>Inverso Grupal:</h3>
        <span runat="server" id="txtCifradoInversoGrupal"/>
	</form>
</body>
</html>
