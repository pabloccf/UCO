package Ejerc1.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Ejerc1.src.DAOs.CriticaDAO;
import Ejerc1.src.Ej2.CriticaDTO;

/**
 * Servlet encargado de ver el listado de las Criticas creadas
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/ListadoCriticas")
public class ListadoCriticas extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Es el constructor del servlet.
	 */
	public ListadoCriticas() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * Esta función del servlet llama a las funciones necesarias de CriticaDAO que
	 * se encargan de devolver una lista de todas las criticas de la base
	 * de datos
	 * 
	 * @param critica es el objeto de tipo CriticaDAO que se encarga de dar acceso a
	 *                las
	 *                diferentes funciones de dicho DAO
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			CriticaDAO critica = new CriticaDAO();
			ArrayList<CriticaDTO> listaCriticas = new ArrayList<CriticaDTO>();
			listaCriticas = critica.ObtenerTodasCriticas();

			PrintWriter salida = response.getWriter();

			salida.println("<html>");
			salida.println("<title>Lista Criticas</title>");
			salida.println("<body>");

			salida.println("<p>Listado de criticas:</p>");
			for (int i = 0; i < listaCriticas.size(); i++) {
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
				salida.println("Cantidad de valoraciones: " + listaCriticas.get(i).getCantidadValoraciones());
				salida.println("<br>");
				salida.println("ID: " + listaCriticas.get(i).getID() + "</p>");
			}

			salida.println("</body></html>");
			RequestDispatcher r = request.getRequestDispatcher("BorrarValorarCritica.html");
			r.include(request, response);
			salida.println("<br>");
			RequestDispatcher dispatcher = request.getRequestDispatcher("plantilla.html");
			dispatcher.include(request, response);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
