package Ej2;

import java.util.ArrayList;
import DAOs.CriticaDAO;

/**
 * Esta clase es la que se encarga de las funciones principales que puede tener un usuario dentro de nuestro programa
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */

public class GestorCritica {
	
	private ArrayList<CriticaDTO> reviews = new ArrayList<CriticaDTO>();
	private static GestorCritica instance = null; 
    public static GestorCritica getInstance() { 
        if (instance == null) {
            instance = new GestorCritica();
        }

        return instance;
    }    
    private GestorCritica() {
    	
    }
    
	/**
	 * Esta función es la que se encarga de añadir la crítica al fichero
	 * @param critica Es un objeto de tipo CriticaDTO que contiene los datos de la critica
	 */
    public void CrearCritica(CriticaDTO critica) {
    	//Metemos la critica donde se tenga que almacenar, solo recoge la critica y almacena
        CriticaDAO review = new CriticaDAO();

        review.crearCritica(critica);
	}
    
	/**
	 * Esta función es la que se encarga de actualizar la crítica 
	 * @param criticaAntigua Es un objeto de tipo CriticaDTO que contiene los datos de la anterior critica
	 * @param criticaNueva Es un objeto de tipo CriticaDTO que contiene los nuevos datos sobre esa critica
	 * @return Devuelve true en el caso de que se haya actualizado correctamente la critica o false en caso de que no se haya actualizado correctamente
	 */
    public void ActualizarCritica(CriticaDTO criticaAntigua, CriticaDTO criticaNueva) {
    	//Buscamos si existe la critica en el almacenamiento, si existe se reemplaza por la nueva y sino pues error feo, devuelvo false    	
    	CriticaDAO review = new CriticaDAO();
    	review.actualizarCritica(criticaNueva, criticaAntigua);
    }
    
	/**
	 * Esta función es la que se encarga de buscar la crítica y devolverla
	 * @param titulo Es el título de la crítica que desea obtener
	 * @return Devuelve la crítica en caso de encontrarla o null en caso de no encontrarla
	 */
	public CriticaDTO ObtenerCritica(String titulo) {
    	//Buscamos la critica con el titulo y la devuelve
    	CriticaDAO critica = new CriticaDAO();
    	CriticaDTO criticaBuena = new CriticaDTO();
    	criticaBuena = critica.obtenerCriticaTitulo(titulo);
    	return criticaBuena;
    }
    
	/**
	 * Esta función elimina la crítica de la lista
	 * @param titulo Es el título de la crítica que el usuario desea eliminar
	 * @return Devuelve true en caso de que se haya eliminado correctamente la crítica o false en caso contrario
	 */
    public void EliminarCritica(String titulo) {
    	CriticaDAO critica = new CriticaDAO();
    	critica.eliminarCritica(titulo);
    }

	/**
	 * Esta función imprime por pantalla cada uno de los campos de la crítiaca
	 */
    public void mostrarCriticas() {
    	CriticaDAO critica = new CriticaDAO();
		reviews = critica.ObtenerTodasCriticas();
		
		for (int i = 0; i < reviews.size(); i++) {
			System.out.println("Titulo: "+reviews.get(i).getTitulo());
			System.out.println("Puntuacion: "+reviews.get(i).getPuntuacion());
			System.out.println("Texto: "+reviews.get(i).getTexto());
			System.out.println("Valoracion: "+reviews.get(i).getValoracion());
			System.out.println("Autor: "+reviews.get(i).getOwner());
			System.out.println("\n");

		}
    }
    
	/**
	 * Esta función va recorriendo el fichero crítica por crítica y si pertenece al usuario la añade a la lista
	 * @param username Es el nick del usuario
	 * @return Devuelve la lista con la crítica del usuario encontrada
	 */
    public ArrayList<CriticaDTO> buscarCriticasUsuario (String username) {
        ArrayList<CriticaDTO> result = new ArrayList<CriticaDTO>();
        int cont = 0;
        //Ir critica a critica y si pertenece al usuario "username" añadirla a la lista que vamos a devolver
		for (int i = 0; i < reviews.size(); i++) {
			if(reviews.get(i).getOwner().equals(username)) {
				result.add(reviews.get(i));
				cont++;
			}
		}
		if(cont == 0) {
			System.out.println("No se ha encontrado ninguna critica con ese titulo.");
		}

		return result;
    }
}
