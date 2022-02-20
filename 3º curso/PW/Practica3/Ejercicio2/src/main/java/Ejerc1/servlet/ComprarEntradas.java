package Ejerc1.servlet;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Ejerc1.src.Ej2.GestorEspectaculos;

/**
 * Servlet encargado de comprar entradas
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/ComprarEntradas")
public class ComprarEntradas extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Este es el contructor del servlet
	 */
	public ComprarEntradas() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.sendRedirect("/Ejercicio2/ComprarEntradas.html");
	}

	/**
	 * Esta funcion del servlet es la que se encarga de crear un gestor que llame a
	 * las funciones que gestionan el numero de entradas
	 * disponibles y su compra
	 * 
	 * @param gestor es el objeto de tipo GestorEspectaculos que se utiliza para
	 *               llamar a determinadas funciones
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			String titulo = request.getParameter("titulo");
			String entradas_str = request.getParameter("EntradasVendidas");
			int entradas = Integer.parseInt(entradas_str);

			GestorEspectaculos gestor = new GestorEspectaculos();

			if (gestor.ComprarEntrada(entradas, titulo)) {
				response.sendRedirect("/Ejercicio2/VentanaComprarEntradas.html");
			}

			else {
				RequestDispatcher dispatcher = request.getRequestDispatcher("VentanaNoComprarEntradas.html");
				dispatcher.include(request, response);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
