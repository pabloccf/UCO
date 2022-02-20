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
import Ejerc1.src.Ej2.UserDTO;

/**
 * Servlet encargado de valorar una critica
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/ValorarCritica")
public class ValorarCritica extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Es el constructor del servlet.
	 */
	public ValorarCritica() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * Esta función del servlet se encarga de llamar a las funciones necesarias de
	 * CriticaDAO para establecer la valoracion de una critica
	 * 
	 * @param critica es el objeto del tipo CriticaDAO que permite acceder a las
	 *                funciones de CriticaDAO
	 * @param usuario es el objeto del tipo UserDTO donde se almacena el usuario que
	 *                relaiza la critica
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			String valoracion_str = request.getParameter("valoracion");
			int valoracion = Integer.parseInt(valoracion_str);
			UserDTO usuario = new UserDTO();
			CriticaDAO critica = new CriticaDAO();
			String id_str = request.getParameter("id");
			int id = Integer.parseInt(id_str);
			CriticaDTO critica1 = new CriticaDTO();
			int contador = 0;

			usuario.setUsername((String) request.getSession().getAttribute("username"));
			ArrayList<CriticaDTO> listaCriticasMias = new ArrayList<CriticaDTO>();
			listaCriticasMias = critica.ObtenerTodasCriticas();

			for (int i = 0; i < listaCriticasMias.size(); i++) {
				if ((id == listaCriticasMias.get(i).getID())
						&& (!listaCriticasMias.get(i).getOwner().equals(usuario.getUsername()))) {
					listaCriticasMias.get(i).setValoracion((listaCriticasMias.get(i).getValoracion() + valoracion) / 2);
					listaCriticasMias.get(i)
							.setCantidadValoraciones(listaCriticasMias.get(i).getCantidadValoraciones() + 1);
					listaCriticasMias.get(i).setID(listaCriticasMias.get(i).getID());
					listaCriticasMias.get(i).setTituloEspectaculo(listaCriticasMias.get(i).getTituloEspectaculo());
					listaCriticasMias.get(i).setOwner(listaCriticasMias.get(i).getOwner());
					listaCriticasMias.get(i).setTexto(listaCriticasMias.get(i).getTexto());
					listaCriticasMias.get(i).setPuntuacion(listaCriticasMias.get(i).getPuntuacion());
					listaCriticasMias.get(i).setTitulo(listaCriticasMias.get(i).getTitulo());
					critica1 = listaCriticasMias.get(i);
					contador++;

					critica.actualizarCritica(critica1, listaCriticasMias.get(i));
					RequestDispatcher dispatcher = request.getRequestDispatcher("VentanaValorarCritica.html");
					dispatcher.include(request, response);
				}
			}

			if (contador == 0) {
				RequestDispatcher dispatcher = request.getRequestDispatcher("VentanaNoValorarCritica.html");
				dispatcher.include(request, response);
			}

		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
