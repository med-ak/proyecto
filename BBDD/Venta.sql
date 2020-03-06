--
-- PostgreSQL database dump
--

-- Dumped from database version 10.10
-- Dumped by pg_dump version 10.10

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: venta; Type: SCHEMA; Schema: -; Owner: postgres
--

CREATE SCHEMA venta;


ALTER SCHEMA venta OWNER TO postgres;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: clientes; Type: TABLE; Schema: venta; Owner: postgres
--

CREATE TABLE venta.clientes (
    id_cliente integer NOT NULL,
    nombre character varying(30) NOT NULL,
    apellidos character varying(30) NOT NULL,
    dni character varying(30) NOT NULL,
    telefono character varying(30) NOT NULL,
    email character varying(30) NOT NULL
);


ALTER TABLE venta.clientes OWNER TO postgres;

--
-- Name: clientes_idCliente_seq; Type: SEQUENCE; Schema: venta; Owner: postgres
--

CREATE SEQUENCE venta."clientes_idCliente_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE venta."clientes_idCliente_seq" OWNER TO postgres;

--
-- Name: clientes_idCliente_seq; Type: SEQUENCE OWNED BY; Schema: venta; Owner: postgres
--

ALTER SEQUENCE venta."clientes_idCliente_seq" OWNED BY venta.clientes.id_cliente;


--
-- Name: clientes id_cliente; Type: DEFAULT; Schema: venta; Owner: postgres
--

ALTER TABLE ONLY venta.clientes ALTER COLUMN id_cliente SET DEFAULT nextval('venta."clientes_idCliente_seq"'::regclass);


--
-- Data for Name: clientes; Type: TABLE DATA; Schema: venta; Owner: postgres
--

COPY venta.clientes (id_cliente, nombre, apellidos, dni, telefono, email) FROM stdin;
2	ghfdgh	fdghdfg	hfdgh	fdghfdghfd	fdgh
17	aaaaa	aaaaaa	aaaaa	aaaaaa	aaaaaa
19	aaaaaaaaaa	aaaaaaaaaa	aaaaaaaaaaaa	aaaaaaaaaaaa	aaaaaaaaa
20	ssssss	ssssssssss	sssssssssssssss	ssssssssss	sssssss
22	hgfd	ghfg	hfghf	hfgh	fghfgh
24	retr	445tert	terter	45tertert	retert
25	uhdhd	dfgdf	gdfg	dfg	dfgfdg
\.


--
-- Name: clientes_idCliente_seq; Type: SEQUENCE SET; Schema: venta; Owner: postgres
--

SELECT pg_catalog.setval('venta."clientes_idCliente_seq"', 26, true);


--
-- Name: clientes clientes_pkey; Type: CONSTRAINT; Schema: venta; Owner: postgres
--

ALTER TABLE ONLY venta.clientes
    ADD CONSTRAINT clientes_pkey PRIMARY KEY (id_cliente);


--
-- PostgreSQL database dump complete
--

