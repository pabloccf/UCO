package Ejerc1.src.DAOs;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

import Ejerc1.src.Ej2.EspectaculoDTO;

/**
 * DAO encargado de escribir todos los espectáculos del sistema en la base de datos
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */

public class EspectaculoDAO {
	/**
	 * Es el constructor de la clase EspectaculoDAO
	 */
	public EspectaculoDAO(){}

	/** 
	 * Esta es la función encargada de añadir a la base de datos un nuevo objeto espectaculo
	 * @param espectaculo Es un objeto de tipo EspectaculoDTO que se quiere añadir a la base de datos
	 */
	public void crearEspectaculo(EspectaculoDTO espectaculo) {
	    try{
	        Connection connection = null;
	        Class.forName("com.mysql.jdbc.Driver");
	        connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
	        PreparedStatement ps = connection.prepareStatement("INSERT INTO `Espectaculos` values(?,?,?,?,?,?,?)");

	            ps.setString(1, espectaculo.getTitulo());
	            ps.setString(2, espectaculo.getDescripcion());
	            ps.setString(3, espectaculo.getCategoria());
	            ps.setInt(4, espectaculo.getAforo());
	            ps.setInt(5, espectaculo.getEntradasVendidas());
	            ps.setString(6, espectaculo.getLocalidad());
	            ps.setString(7, espectaculo.getFecha());

	            ps.executeUpdate();

	            if (ps != null) { 
	                ps.close(); 
	            }

	            connection.close();
	    } catch (Exception e){
	        System.out.println(e);
	    }
	}

	/**
	 * Esta función se encarga de eliminar un espectaculo de la base de datos
	 * @param espectaculo Es un objeto de tipo EspectaculoDTO que se quiere eliminar de la base de datos
	 */
	public void eliminarEspectaculo(EspectaculoDTO espectaculo) {
		try{
			Connection connection = null;
	        Class.forName("com.mysql.jdbc.Driver");
	        connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
			PreparedStatement ps = connection.prepareStatement("DELETE FROM Espectaculos WHERE Titulo = ?");

			ps.setString(1, espectaculo.getTitulo());

			ps.executeUpdate();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/** 
	 * Esta función se encarga de buscar y devolver de la base de datos los shows que coincidan con la el título recibido en la función
	 * @param titulo Es el título de la función de la se quieren buscar los espectaculos
	 * @return Devuelve un objeto de tipo espectaculo al encontrar relación con el título recibido en la función. En caso de no encontrar nada devuelve NULL
	 */
	public EspectaculoDTO obtenerMostrarPorTitulo(String titulo) {
	    EspectaculoDTO espectaculo = new EspectaculoDTO();

	    try{
	        Connection connection = null;
	        Class.forName("com.mysql.jdbc.Driver");
	        connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
	        Statement statement = connection.createStatement();

	        String sqlString = "select e.Titulo, e.Descripcion, e.Categoria, e.Aforo, e.EntradasVendidas, e.Localidad, e.Fecha from `Espectaculos` e where e.Titulo = '" + titulo + "'";
	        ResultSet rs = statement.executeQuery(sqlString);

	        while (rs.next()) {
	            espectaculo.setTitulo(rs.getString("e.Titulo"));
	            espectaculo.setDescripcion(rs.getString("e.Descripcion"));
	            espectaculo.setCategoria(rs.getString("e.Categoria"));
	            espectaculo.setAforo(rs.getInt("e.Aforo"));
	            espectaculo.setEntradasVendidas(rs.getInt("e.EntradasVendidas"));
	            espectaculo.setLocalidad(rs.getString("e.Localidad"));
	            espectaculo.setFecha(rs.getString("e.Fecha"));
	        }
	            
	        if (statement != null) {
				statement.close();
			}

	        return espectaculo;
	    } catch (Exception e){
	        System.out.println(e);
	    }

	    return null;
	}

	/** 
	 * Esta función busca y devuelve de la base de datos todos los espectaculos del sistema
	 * @return Devuelve la lista de espectaculos que se han encontrado en la base de datos. En caso de no encontrar nada devuelve NULL
	 */
	public ArrayList<EspectaculoDTO> ObtenerTodosEspectaculos() {        
	    ArrayList<EspectaculoDTO> espectaculos = new ArrayList<EspectaculoDTO>();

	    try{
	        Connection connection = null;
	        Class.forName("com.mysql.jdbc.Driver");
	        connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
	        Statement statement = connection.createStatement();

	        String sqlString = "select e.Titulo, e.Descripcion, e.Categoria, e.Aforo, e.EntradasVendidas, e.Localidad, e.Fecha from `Espectaculos` e";
	        ResultSet rs = statement.executeQuery(sqlString);

	        while (rs.next()) {
	            EspectaculoDTO espectaculo = new EspectaculoDTO();

	            espectaculo.setTitulo(rs.getString("e.Titulo"));
	            espectaculo.setDescripcion(rs.getString("e.Descripcion"));
	            espectaculo.setCategoria(rs.getString("e.Categoria"));
	            espectaculo.setAforo(rs.getInt("e.Aforo"));
	            espectaculo.setEntradasVendidas(rs.getInt("e.EntradasVendidas"));
	            espectaculo.setLocalidad(rs.getString("e.Localidad"));
	            espectaculo.setFecha(rs.getString("e.Fecha"));
	                
	            espectaculos.add(espectaculo);
	        }
				
	        if (statement != null) {
				statement.close();
			}

	        return espectaculos;
	    } catch (Exception e){
	        System.out.println(e);
	    }

	    return null; 
	}	    
	
	/** 
	 * Esta función se encarga de buscar y devolver de la base de datos los espectaculos que coincidan con la categoría 
	 * @param categoria Es la categoría de la función de la se quieren buscar los espectaculos
	 * @return Devuelve un objeto de tipo espectaculo al encontrar relación con el título recibido en la función. En caso de no encontrar nada devuelve NULL
	 */
	public EspectaculoDTO obtenerMostrarPorCategoria(String categoria) {
	    EspectaculoDTO espectaculo = new EspectaculoDTO();

	    try{
	        Connection connection = null;
	        Class.forName("com.mysql.jdbc.Driver");
	        connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
	        Statement statement = connection.createStatement();

	        String sqlString = "select e.Titulo, e.Descripcion, e.Categoria, e.Aforo, e.EntradasVendidas, e.Localidad, e.Fecha from `Espectaculos` e where e.Categoria = '" + categoria + "'";
	        ResultSet rs = statement.executeQuery(sqlString);

	        while (rs.next()) {
	            espectaculo.setTitulo(rs.getString("e.Titulo"));
	            espectaculo.setDescripcion(rs.getString("e.Descripcion"));
	            espectaculo.setCategoria(rs.getString("e.Categoria"));
	            espectaculo.setAforo(rs.getInt("e.Aforo"));
	            espectaculo.setEntradasVendidas(rs.getInt("e.EntradasVendidas"));
	            espectaculo.setLocalidad(rs.getString("e.Localidad"));
	            espectaculo.setFecha(rs.getString("e.Fecha"));

	        }
	            
	        if (statement != null) {
				statement.close();
			}

	        return espectaculo;
	    } catch (Exception e){
	        System.out.println(e);
	    }

	    return null;
	}
	
	/**
	 * Esta función se encarga de actualizar los espectaculos en la base de datos 
	 * @param espectaculo Es un objeto de tipo EspectaculoDTO que se quiere actualizar en la base de datos
	 */
	public void MeterEntradasVendidas(EspectaculoDTO espectaculo) {
	    //Espectaculo espectaculo = new Espectaculo();

	    try{
	    	Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");

	        String sql = "UPDATE Espectaculos SET Titulo = ?, Descripcion = ?, Categoria = ?, Aforo = ?, EntradasVendidas = ?, Localidad = ?, Fecha = ? WHERE Titulo = ?";
	        PreparedStatement ps = connection.prepareStatement(sql);

	        ps.setString(1, espectaculo.getTitulo());
            ps.setString(2, espectaculo.getDescripcion());
            ps.setString(3, espectaculo.getCategoria());
            ps.setInt(4, espectaculo.getAforo());
            ps.setInt(5, espectaculo.getEntradasVendidas());
            ps.setString(6, espectaculo.getLocalidad());
            ps.setString(7, espectaculo.getFecha());
	        ps.setString(8, espectaculo.getTitulo());


				     
            ps.executeUpdate();
            ps.close();
            
	    } catch (Exception e){
	        System.out.println(e);
	    }
	}

	/** 
	 * Esta función se encarga de buscar y devolver de la base de datos los espectaculos que coincidan con la fecha
	 * @param fecha Es la fecha de la función de la se quieren buscar los espectaculos
	 * @return Devuelve un objeto de tipo EspectaculoDTO al encontrar relación con la fecha recibido en la función. En caso de no encontrar nada devuelve NULL
	 */
	public EspectaculoDTO obtenerMostrarPorFecha(String fecha) {
	    EspectaculoDTO espectaculo = new EspectaculoDTO();

	    try{
	        Connection connection = null;
	        Class.forName("com.mysql.jdbc.Driver");
	        connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
	        Statement statement = connection.createStatement();

	        String sqlString = "select e.Titulo, e.Descripcion, e.Categoria, e.Aforo, e.EntradasVendidas, e.Localidad, e.Fecha from `Espectaculos` e where e.Fecha = '" + fecha + "'";
	        ResultSet rs = statement.executeQuery(sqlString);

	        while (rs.next()) {
	            espectaculo.setTitulo(rs.getString("e.Titulo"));
	            espectaculo.setDescripcion(rs.getString("e.Descripcion"));
	            espectaculo.setCategoria(rs.getString("e.Categoria"));
	            espectaculo.setAforo(rs.getInt("e.Aforo"));
	            espectaculo.setEntradasVendidas(rs.getInt("e.EntradasVendidas"));
	            espectaculo.setLocalidad(rs.getString("e.Localidad"));
	            espectaculo.setFecha(rs.getString("e.Fecha"));

	        }
				
	        if (statement != null) {
				statement.close();
			}

	        return espectaculo;
	    } catch (Exception e){
	        System.out.println(e);
	    }

	    return null;
	}
}