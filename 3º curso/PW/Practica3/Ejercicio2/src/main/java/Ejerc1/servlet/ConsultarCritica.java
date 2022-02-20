package Ejerc1.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Ejerc1.src.DAOs.CriticaDAO;
import Ejerc1.src.Ej2.CriticaDTO;
import java.util.ArrayList;

/**
 * Servlet encargado de consultar critica
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/ConsultarCritica")
public class ConsultarCritica extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Este es el contructor del servlet
	 */
	public ConsultarCritica() {
		super();
		// TODO Auto-generated constructor stub
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.sendRedirect("/Ejercicio2/BusquedaCriticaTitulo.html");
	}

	/**
	 * Esta funcion del servlet es la que a traves de las funciones de un objeto
	 * CriticaDAO devuelve una critica
	 * 
	 * @param critica es el objeto del tipo CriticaDAO que se utiliza para guardar
	 *                la critica.
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			CriticaDAO critica = new CriticaDAO();
			ArrayList<CriticaDTO> listaCriticas = new ArrayList<CriticaDTO>();
			listaCriticas = critica.ObtenerTodasCriticas();
			int contador = 0;

			String titulo = request.getParameter("titulo");

			PrintWriter salida = response.getWriter();
			salida.println("<html>");
			salida.println("<title>Consultar Criticas</title>");
			salida.println("<body>");

			// salida.println("[");
			for (int i = 0; i < listaCriticas.size(); i++) {
				if (listaCriticas.get(i).getTitulo().equals(titulo)) {
					/**
					 * salida.println("{");
					 * salida.println("\"titulo\":\""+listaCriticas.get(i).getTitulo()+"\",");
					 * salida.println("\"puntuacion\":\""+listaCriticas.get(i).getPuntuacion()+"\",");
					 * salida.println("\"texto\":\""+listaCriticas.get(i).getTexto()+"\",");
					 * salida.println("\"valoracion\":\""+listaCriticas.get(i).getValoracion()+"\",");
					 * salida.println("\"autor\":\""+listaCriticas.get(i).getOwner()+"\",");
					 * salida.println("\"cantidadValoraciones\":\""+listaCriticas.get(i).getCantidadValoraciones()+"\",");
					 * salida.println("\"id\":\""+listaCriticas.get(i).getID()+"\"");
					 * salida.println(i==listaCriticas.size()-1 ? "}" : "},");
					 **/

					if (contador == 0) {
						salida.println("<p>Listado de criticas</p>");
					}
					salida.println("<p>Titulo: " + listaCriticas.get(i).getTitulo());
					salida.println("<br>");
					salida.println("Puntuacion: " + listaCriticas.get(i).getPuntuacion());
					salida.println("<br>");
					salida.println("Texto: " + listaCriticas.get(i).getTexto());
					salida.println("<br>");
					salida.println("Valoracion: " + listaCriticas.get(i).getValoracion());
					salida.println("<br>");
					salida.println("Autor: " + listaCriticas.get(i).getOwner());
					salida.println("<br>");
					salida.println(
							"Cantidad de valoraciones: " + listaCriticas.get(i).getCantidadValoraciones() + "</p>");
					contador++;
				}
			}
			/**
			 * salida.println("]");
			 * salida.close();
			 **/

			if (contador == 0) {
				response.setStatus(404);
				RequestDispatcher dispatcher = request.getRequestDispatcher("VentanaNoConsultarCritica.html");
				dispatcher.include(request, response);
				// salida.println("Lo sentimos, no esta disponible dicha critica");
			}

			salida.println("</body></html>");
			RequestDispatcher dispatcher = request.getRequestDispatcher("plantilla.html");
			dispatcher.include(request, response);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
