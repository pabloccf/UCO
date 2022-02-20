package Ejerc1.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Ejerc1.src.DAOs.CriticaDAO;
import Ejerc1.src.Ej2.CriticaDTO;

/**
 * Servlet encargado de devolver las criticas creadas por el usuario
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/DevolverCriticaPropia")
public class DevolverCriticaPropia extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Es el constructor del servlet.
	 */
	public DevolverCriticaPropia() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * Esta funcion del servlet a partir de las funciones de CriticaDAO se encarga
	 * de buscar y devolver todas las criticas que ha hecho el propio usuario
	 * 
	 * @param critica es el objeto del tipo CriticaDAO que se utiliza para guardar
	 *                la información de las criticas
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
			int contador = 0;

			PrintWriter salida = response.getWriter();
			salida.println("[");
			for (int i = 0; i < listaCriticas.size(); i++) {
				if (listaCriticas.get(i).getOwner().equals((String) request.getSession().getAttribute("username"))) {
					salida.println("{");
					salida.println("\"titulo\":\"" + listaCriticas.get(i).getTitulo() + "\",");
					salida.println("\"puntuacion\":\"" + listaCriticas.get(i).getPuntuacion() + "\",");
					salida.println("\"texto\":\"" + listaCriticas.get(i).getTexto() + "\",");
					salida.println("\"valoracion\":\"" + listaCriticas.get(i).getValoracion() + "\",");
					salida.println("\"autor\":\"" + listaCriticas.get(i).getOwner() + "\",");
					salida.println(
							"\"cantidadValoraciones\":\"" + listaCriticas.get(i).getCantidadValoraciones() + "\"");
					salida.println(i == listaCriticas.size() - 1 ? "}" : "},");
					contador++;
				}
			}
			if (contador == 0) {
				response.setStatus(404);
			}
			salida.println("]");

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
