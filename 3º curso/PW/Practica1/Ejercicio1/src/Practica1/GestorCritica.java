package Practica1;
import java.io.*;
import java.util.ArrayList;

/**
 * Esta clase es la que se encarga de las funciones principales que puede tener un usuario dentro de nuestro programa
 * @author José Ángel Dorado, Pablo López y Pablo Ibañez
 * @version openjdk 11.0.11 2021-04-20
 */

public class GestorCritica {
	
	private ArrayList<Critica> reviews = new ArrayList<Critica>();
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
	 * @param critica Es un objeto de tipo Critica que contiene los datos de la critica
	 */
    public void CrearCritica(Critica critica) {
    	//Metemos la critica donde se tenga que almacenar, solo recoge la critica y almacena
    	if(critica != null) {
    		reviews.add(critica);
    		escribirFichero();    		
    	}
	}
    
	/**
	 * Esta función es la que se encarga de actualizar la crítica 
	 * @param criticaAntigua Es un objeto de tipo critica que contiene los datos de la anterior critica
	 * @param criticaNueva Es un objeto de tipo critica que contiene los nuevos datos sobre esa critica
	 * @return Devuelve true en el caso de que se haya actualizado correctamente la critica o false en caso de que no se haya actualizado correctamente
	 */
    public boolean ActualizarCritica(Critica criticaAntigua, Critica criticaNueva) {
    	//Buscamos si existe la critica en el almacenamiento, si existe se reemplaza por la nueva y sino pues error feo, devuelvo false
    	if(reviews.contains(criticaAntigua)) {
			int index = reviews.indexOf(criticaAntigua);
			reviews.set(index, criticaNueva);

			return true;
		}

		return false;
    }
    
	/**
	 * Esta función es la que se encarga de buscar la crítica y devolverla
	 * @param titulo Es el título de la crítica que desea obtener
	 * @return Devuelve la crítica en caso de encontrarla o null en caso de no encontrarla
	 */
	public Critica ObtenerCritica(String titulo) {
    	//Buscamos la critica con el titulo y la devuelve
    	for (int i = 0; i < reviews.size(); i++) {
			if(titulo.equals(reviews.get(i).getTitulo())) {
				return reviews.get(i);
			}
		}

		return null;
    }
    
	/**
	 * Esta función elimina la crítica de la lista
	 * @param titulo Es el título de la crítica que el usuario desea eliminar
	 * @return Devuelve true en caso de que se haya eliminado correctamente la crítica o false en caso contrario
	 */
    public boolean EliminarCritica(String titulo) {
    	for (int i = 0; i < reviews.size(); i++) {
			if(titulo.equals(reviews.get(i).getTitulo())) {
				reviews.remove(reviews.get(i));
				return true;
			}
		}

		return false;
    }

	/**
	 * Esta función imprime por pantalla cada uno de los campos de la crítiaca
	 */
    public void mostrarCriticas() {
		for (int i = 0; i < reviews.size(); i++) {
			System.out.println(reviews.get(i).getTitulo());
			System.out.println(reviews.get(i).getPuntuacion());
			System.out.println(reviews.get(i).getTexto());
			System.out.println(reviews.get(i).getValoracion());
			System.out.println(reviews.get(i).getOwner());
		}
    }
    
	/**
	 * Esta función va recorriendo el fichero crítica por crítica y si pertenece al usuario la añade a la lista
	 * @param username Es el nick del usuario
	 * @return Devuelve la lista con la crítica del usuario encontrada
	 */
    public ArrayList<Critica> buscarCriticasUsuario (String username) {
        ArrayList<Critica> result = new ArrayList<Critica>();
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

	/**
	 * Esta función lee el fichero
	 */
	public void leerFichero() {
		File fichero = null;
    	FileReader fr = null;
    	BufferedReader br = null;
    	
    	try {
    		//Apertura del fichero
    		fichero = new File ("/home/pablo/eclipse-workspace/Practica1/src/Practica1/Criticas.txt");
    		fr = new FileReader (fichero);
    		br = new BufferedReader (fr);
    		
    		//Lectura del fichero
    		String linea;
            while((linea=br.readLine())!=null) {

				Critica critica1 = new Critica();
            	critica1.setTitulo(linea);

            	//Puntuacion
            	int n = Integer.parseInt(br.readLine());
            	critica1.setPuntuacion(n);
            	//Texto
            	critica1.setTexto(br.readLine());
            	//valoracion
            	n = Integer.parseInt(br.readLine());
            	critica1.setValoracion(n);
            	//Autor
            	critica1.setOwner(br.readLine());

				reviews.add(critica1);
            }
    	}

    	catch(Exception e) {
			e.printStackTrace();
		}finally {
			try{
				if(null != fr) {
					fr.close();
				}
			}catch (Exception e2) {
				e2.printStackTrace();
			}
		}
	}

	/**
	 * Esta función escribe en el fichero
	 */
	public void escribirFichero() {
		FileWriter fichero = null;
        PrintWriter pw = null;
    	
        try {
        	fichero = new FileWriter("/home/pablo/eclipse-workspace/Practica1/src/Practica1/Criticas.txt");
        	pw = new PrintWriter(fichero);
			for (int i = 0; i < reviews.size(); i++){
				pw.println(reviews.get(i).getTitulo());
				pw.println(reviews.get(i).getPuntuacion());
				pw.println(reviews.get(i).getTexto());
				pw.println(reviews.get(i).getValoracion());
				pw.println(reviews.get(i).getOwner());
			}
        }

    	catch(Exception e) {
			e.printStackTrace();
		}finally {
			try{
				if(null != pw) {
					pw.close();
				}
			}catch (Exception e2) {
				e2.printStackTrace();
			}
		}
	}
	@Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((reviews == null) ? 0 : reviews.hashCode());
        return result;
    }
	@Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        GestorCritica other = (GestorCritica) obj;
        if (reviews == null) {
            if (other.reviews != null)
                return false;
        } else if (!reviews.equals(other.reviews))
            return false;
        return true;
    }
}