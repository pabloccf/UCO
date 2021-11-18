package Practica2;

public class Espectaculo {
		
		private String titulo;
		private String descripcion;
		private String categoria;
		private Integer aforo;
		private Integer entradasVendidas;
		private String localidad;
		
		public Espectaculo(String titulo, String descripcion, String categoria, Integer aforo) {
			super();
			this.titulo = titulo;
			this.descripcion = descripcion;
			this.categoria = categoria;
			this.aforo = aforo;
			this.entradasVendidas = 0;
			this.localidad = "";
		}
		public Espectaculo(String titulo, String descripcion, String categoria, Integer aforo, Integer entradasVendidas) {
			super();
			this.titulo = titulo;
			this.descripcion = descripcion;
			this.categoria = categoria;
			this.aforo = aforo;
			this.entradasVendidas = entradasVendidas;
			this.localidad = "";
		}

		public String getTitulo() {
			return titulo;
		}

		public void setTitulo(String titulo) {
			this.titulo = titulo;
		}

		public String getDescripcion() {
			return descripcion;
		}

		public void setDescripcion(String descripcion) {
			this.descripcion = descripcion;
		}

		public String getCategoria() {
			return categoria;
		}

		public void setCategoria(String categoria) {
			this.categoria = categoria;
		}

		public Integer getAforo() {
			return aforo;
		}

		public void setAforo(Integer aforo) {
			this.aforo = aforo;
		}
		
		public Integer getEntradasVendidas() {
			return entradasVendidas;
		}
		public void setEntradasVendidas(Integer entradasVendidas) {
			this.entradasVendidas = entradasVendidas;
		}
		
		public String getLocalidad() {
			return localidad;
		}
		public void setLocalidad(String localidad) {
			this.localidad = localidad;
		}
		

}

