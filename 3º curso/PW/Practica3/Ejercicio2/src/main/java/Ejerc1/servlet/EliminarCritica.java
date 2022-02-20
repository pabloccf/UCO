package Ejerc1.servlet;

import java.io.IOException;
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
 * Servlet encargado de eliminar una critica
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/EliminarCritica")
public class EliminarCritica extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Es el constructor del servlet.
	 */
	public EliminarCritica() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * Esta función del servlet utiliza las funciones del archivo CriticaDAO para
	 * buscar y borrar una critica
	 * 
	 * @param critica es el objeto del tipo CriticaDAO que se utiliza para almacenar
	 *                la critica que se quiere borrar
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
			String id_str = request.getParameter("id");
			int id = Integer.parseInt(id_str);
			ArrayList<CriticaDTO> listaCriticas = new ArrayList<CriticaDTO>();
			listaCriticas = critica.ObtenerTodasCriticas();
			CriticaDTO critica1 = new CriticaDTO();

			for (int i = 0; i < listaCriticas.size(); i++) {
				if (listaCriticas.get(i).getID() == id) {
					critica1 = listaCriticas.get(i);
				}
			}

			if (critica1.getOwner().equals((String) (request.getSession().getAttribute("username")))) {
				CriticaDAO critica2 = new CriticaDAO();
				critica2.eliminarCritica(id);
				RequestDispatcher dispatcher = request.getRequestDispatcher("VentanaEliminarCritica.html");
				dispatcher.include(request, response);
			}

			else {
				RequestDispatcher dispatcher = request.getRequestDispatcher("VentanaNoEliminarCritica.html");
				dispatcher.include(request, response);
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
