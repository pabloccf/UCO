package Ejerc1.servlet;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Ejerc1.src.DAOs.EspectaculoDAO;
import Ejerc1.src.Ej2.EspectaculoDTO;

/**
 * Servlet encargado de eliminar un espectaculo
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/EliminarEspectaculo")
public class EliminarEspectaculo extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Es el constructor del servlet.
	 */
	public EliminarEspectaculo() {
		super();
		// TODO Auto-generated constructor stub
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.sendRedirect("/Ejercicio2/EliminarEspectaculo.html");
	}

	/**
	 * Esta función del servlet utiliza las funciones de EspectaculoDAO para borrar
	 * el espectaculo que se recibe como parametro
	 * 
	 * @param espectaculo es el objeto de tipo EspectaculoDAO que se utiliza para
	 *                    llamar a la funcion de eliminar
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			EspectaculoDAO espectaculo = new EspectaculoDAO();
			String titulo = request.getParameter("titulo");
			ArrayList<EspectaculoDTO> lista = new ArrayList<EspectaculoDTO>();
			lista = espectaculo.ObtenerTodosEspectaculos();
			int contador = 0;

			for (int i = 0; i < lista.size(); i++) {
				if (titulo.equals(lista.get(i).getTitulo())) {
					contador++;
				}
			}
			if (contador > 0) {
				espectaculo.eliminarEspectaculo(espectaculo.obtenerMostrarPorTitulo(titulo));
				response.sendRedirect("/Ejercicio2/VentanEliminarEspectaculo.html");
			} else {
				RequestDispatcher dispatcher = request.getRequestDispatcher("VentanaEspectaculoNoEliminado.html");
				dispatcher.include(request, response);
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}