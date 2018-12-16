using System;
using System.Web;
using System.Web.UI;
using System.Collections.Generic;

namespace Cifrado
{

    public partial class Default : System.Web.UI.Page
    {

        public void cifrarMensaje(object sender,EventArgs e){
            String entrada = textoPlano.Text;


            //INVERSO
            //Texto texto1 = new Texto(entrada);
            Inverso inverso = new Inverso(new Texto(entrada));
            txtCifradoInverso.InnerText = inverso.verTexto();


            //INVERSO GRUPAL
            int semillaIG=0;
            //InversoGrupal inversoGrupal = new InversoGrupal(new Texto(entrada),semillaIG);
            if(int.TryParse(txtDesplazamiento.Text,out semillaIG)){
                InversoGrupal ig = new InversoGrupal(new Texto(entrada), semillaIG);
                txtCifradoInversoGrupal.InnerText = ig.verMensaje();    
            }else{
                txtCifradoInversoGrupal.InnerText = "El desplazamiento debe ser un numero y debe ser positivo";
            }



            //CESAR
            //Texto texto2 = new Texto(entrada);
            int semillaC = 0;
            if(int.TryParse(txtDesplazamiento.Text, out semillaC)){
                Cesar c = new Cesar(new Texto(entrada), semillaC);
                txtCifradoCesar.InnerText = c.verMensaje();    
            }else{
                txtCifradoCesar.InnerText = "El desplazamiento debe ser un numero y debe ser positivo";    
            }
        }
    }



    public class Abecedario
    {
        private String letras = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
        private int tamanio;

        public Abecedario()
        {
            tamanio = letras.Length;
        }

        private int posicionDeLetra(char letra)
        {
            int pos = -1;
            for (int i = 0; i < tamanio; i++)
            {
                if (letras[i] == letra)
                {
                    pos = i;
                    break;
                }
            }
            return pos;
        }

        public char desplazarLetraEn(char letra, int desp)
        {
            int posicionLetraEncontrada = posicionDeLetra(letra);
            if (posicionLetraEncontrada >= 0)
            {
                int nuevaPosicion = ((posicionLetraEncontrada + desp) + tamanio) % tamanio;
                return letras[nuevaPosicion];
            }
            return letra;
        }
    }



    public class Texto
    {
        private String texto;
        private int tamanio;
        private int posicionActual;

        public Texto(string texto)
        {
            this.texto = texto;
            tamanio = texto.Length;
            posicionActual = 0;
        }


        public char getCaracter()
        {
            char actual = texto[posicionActual];
            posicionActual++;
            return actual;
        }

        public bool hayMasTexto()
        {
            return posicionActual < tamanio;
        }

        /*Regresa las letras en mayusculas*/
        public char getLetraMayuscula()
        {
            if (hayMasTexto())
            {
                char letra = getCaracter();
                if (!Char.IsLetter(letra))
                {
                    return letra;
                }
                return Char.ToUpper(letra);
            }
            return (char)0;
        }

        public char getSoloLetras()
        {
            if (hayMasTexto())
            {
                char letra = getCaracter();
                if (Char.IsLetter(letra))
                {
                    return letra;
                }
            }

            return (char)0;
        }
    }



    public class Cesar
    {
        private Texto texto;
        private Abecedario abecedario;
        String mensajeCifrado;
        int posicion;

        public Cesar(Texto t, int semilla)
        {
            abecedario = new Abecedario();
            texto = t;
            mensajeCifrado = "";
            posicion = semilla;
            mensajeCifrado = cifrar();
        }

        private String cifrar()
        {
            string tC = "";
            while (texto.hayMasTexto())
            {
                char letra = texto.getLetraMayuscula();
                if ((int)letra != 0)
                {
                    tC += abecedario.desplazarLetraEn(letra, posicion);
                }
            }
            return tC;
        }

        public String verMensaje()
        {
            return mensajeCifrado;
        }
    }


    public class Inverso
    {
        private Stack<Char> pila;
        public Inverso(Texto entrada)
        {
            pila = new Stack<Char>();
            invertirTexto(entrada);
        }

        private void invertirTexto(Texto t)
        {
            while (t.hayMasTexto())
            {
                pila.Push(t.getCaracter());

            }
        }

        public String verTexto()
        {
            string inverso = "";
            foreach (Char obj in pila)
            {
                inverso += obj;
            }
            return inverso;
        }
    }

    public class InversoGrupal{
        private string mensajeInverso;

        public InversoGrupal(Texto t,int desplazamiento){
            int conta = 0;
            string pedazo = "";
            //string nuevo = "";
            while(t.hayMasTexto()){
                if(conta%desplazamiento == 0){
                    Inverso i = new Inverso(new Texto(pedazo));
                    mensajeInverso += i.verTexto();
                    pedazo = "";
                }
                char c = t.getCaracter();
                if(c!=0){
                    pedazo += c;    
                }
                conta++;
            }
            if(pedazo.Length == desplazamiento){
                Inverso i = new Inverso(new Texto(pedazo));
                mensajeInverso += i.verTexto();
            }else{
                mensajeInverso += pedazo;
            }
        }

        public string verMensaje(){
            return mensajeInverso;
        }
    }

}
