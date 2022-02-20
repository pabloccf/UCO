package Ejerc1.servlet;

import java.util.*;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Ejerc1.src.DAOs.EspectaculoDAO;
import Ejerc1.src.Ej2.EspectaculoDTO;

/**
 * Servlet encargado de consultar las diferentes localidades
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/ConsultarLocalidades")
public class ConsultarLocalidades extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Es el constructor del servlet.
	 */
	public ConsultarLocalidades() {
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
		response.sendRedirect("/Ejercicio2/ConsultarLocalidadesDisponibles.html");
	}

	/**
	 * Esta función del servlet utiliza las funciones de EspectaculoDAO para
	 * devolver las localidades disponibles
	 * 
	 * @param espectaculo    Es el objeto tipo espectaculo de espectaculoDTO que
	 *                       guardara la informacion.
	 * @param espectaculoDao Es el objeto tipo espectaculo de espectaculoDAO que se
	 *                       utilizara para acceder a las diferentes funciones del
	 *                       DAO
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			String fecha = request.getParameter("fecha");

			ArrayList<EspectaculoDTO> espectaculo = new ArrayList<EspectaculoDTO>();
			ArrayList<EspectaculoDTO> espectaculosList = new ArrayList<EspectaculoDTO>();

			PrintWriter salida = response.getWriter();
			salida.println("<html>");
			salida.println("<title>Consultar Localidad Espectaculo</title>");
			salida.println("<body>");

			EspectaculoDTO espectaculo1 = new EspectaculoDTO();
			espectaculo1.setFecha(fecha);
			EspectaculoDAO espectaculoDao = new EspectaculoDAO();
			espectaculosList = espectaculoDao.ObtenerTodosEspectaculos();

			int variable = 0;

			for (int x = 0; x < espectaculosList.size(); x++) {
				if (espectaculo1.getFecha().equals(espectaculosList.get(x).getFecha())) {
					if (espectaculosList.get(x).getEntradasVendidas() < espectaculosList.get(x).getAforo()) {
						variable++;
						espectaculo.add(espectaculosList.get(x));
					}
				}
			}
			if (variable > 0) {
				// salida.println("[");
				salida.println("<p>Listado de localidades disponibles segun la fecha introducida:</p>");

				for (int i = 0; i < espectaculo.size(); i++) {
					/**
					 * salida.println("{");
					 * salida.println("\"titulo\":\""+espectaculo.get(i).getTitulo()+"\",");
					 * salida.println("\"categoria\":\""+espectaculo.get(i).getCategoria()+"\",");
					 * salida.println("\"localidad\":\""+espectaculo.get(i).getLocalidad()+"\",");
					 * salida.println(i==espectaculo.size()-1 ? "}" : "},");
					 **/
					salida.println("<p>Titulo: " + espectaculo.get(i).getTitulo());
					salida.println("<br>");
					salida.println("Categoria: " + espectaculo.get(i).getCategoria());
					salida.println("<br>");
					salida.println("Localidad: " + espectaculo.get(i).getLocalidad() + "</p>");
				}

				// salida.println("]");
			}

			else {
				RequestDispatcher dispatcher = request.getRequestDispatcher("VentanaNoConsultarLocalidades.html");
				dispatcher.include(request, response);
			}

			salida.println("</body></html>");
			RequestDispatcher dispatcher = request.getRequestDispatcher("plantilla.html");
			dispatcher.include(request, response);
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
