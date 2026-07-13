if(CONFIG_IEC61850)

    set(IEC61850_DIR ${ZEPHYR_CURRENT_MODULE_DIR})

    set(CONFIG_IEC61850_CONTROL_SERVICE 1)
    set(CONFIG_IEC61850_REPORT_SERVICE 1)
    set(CONFIG_IEC61850_LOG_SERVICE 1)
    set(CONFIG_IEC61850_SERVICE_TRACKING 1)
    set(CONFIG_IEC61850_SETTING_GROUPS 1)
    set(CONFIG_IEC61850_SUPPORT_USER_READ_ACCESS_CONTROL 1)

    # write the detected stuff to this file
    configure_file(
        ${IEC61850_DIR}/config/stack_config.h.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/config/stack_config.h
    )

    set (lib_common_SRCS
    ${IEC61850_DIR}/src/common/string_map.c
    ${IEC61850_DIR}/src/common/map.c
    ${IEC61850_DIR}/src/common/linked_list.c
    ${IEC61850_DIR}/src/common/byte_buffer.c
    ${IEC61850_DIR}/src/common/string_utilities.c
    ${IEC61850_DIR}/src/common/buffer_chain.c
    ${IEC61850_DIR}/src/common/conversions.c
    ${IEC61850_DIR}/src/common/mem_alloc_linked_list.c
    ${IEC61850_DIR}/src/common/simple_allocator.c
    ${IEC61850_DIR}/src/mms/iso_server/iso_connection.c
    ${IEC61850_DIR}/src/mms/iso_server/iso_server.c
    ${IEC61850_DIR}/src/mms/iso_acse/acse.c
    ${IEC61850_DIR}/src/mms/iso_mms/common/mms_type_spec.c
    ${IEC61850_DIR}/src/mms/iso_mms/common/mms_value.c
    ${IEC61850_DIR}/src/mms/iso_mms/common/mms_common_msg.c
    ${IEC61850_DIR}/src/mms/iso_mms/client/mms_client_initiate.c
    ${IEC61850_DIR}/src/mms/iso_mms/client/mms_client_write.c
    ${IEC61850_DIR}/src/mms/iso_mms/client/mms_client_identify.c
    ${IEC61850_DIR}/src/mms/iso_mms/client/mms_client_status.c
    ${IEC61850_DIR}/src/mms/iso_mms/client/mms_client_named_variable_list.c
    ${IEC61850_DIR}/src/mms/iso_mms/client/mms_client_connection.c
    ${IEC61850_DIR}/src/mms/iso_mms/client/mms_client_files.c
    ${IEC61850_DIR}/src/mms/iso_mms/client/mms_client_get_namelist.c
    ${IEC61850_DIR}/src/mms/iso_mms/client/mms_client_get_var_access.c
    ${IEC61850_DIR}/src/mms/iso_mms/client/mms_client_common.c
    ${IEC61850_DIR}/src/mms/iso_mms/client/mms_client_read.c
    ${IEC61850_DIR}/src/mms/iso_mms/client/mms_client_journals.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_read_service.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_file_service.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_association_service.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_identify_service.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_status_service.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_named_variable_list_service.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_value_cache.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_get_namelist_service.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_access_result.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_server.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_server_common.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_named_variable_list.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_domain.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_device.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_information_report.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_journal.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_journal_service.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_server_connection.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_write_service.c
    ${IEC61850_DIR}/src/mms/iso_mms/server/mms_get_var_access_service.c
    ${IEC61850_DIR}/src/mms/iso_cotp/cotp.c
    ${IEC61850_DIR}/src/mms/iso_presentation/iso_presentation.c
    ${IEC61850_DIR}/src/mms/asn1/ber_decode.c
    ${IEC61850_DIR}/src/mms/asn1/asn1_ber_primitive_value.c
    ${IEC61850_DIR}/src/mms/asn1/ber_encoder.c
    ${IEC61850_DIR}/src/mms/asn1/ber_integer.c
    ${IEC61850_DIR}/src/mms/iso_client/iso_client_connection.c
    ${IEC61850_DIR}/src/mms/iso_common/iso_connection_parameters.c
    ${IEC61850_DIR}/src/mms/iso_session/iso_session.c
    ${IEC61850_DIR}/src/iec61850/client/client_control.c
    ${IEC61850_DIR}/src/iec61850/client/client_report_control.c
    ${IEC61850_DIR}/src/iec61850/client/client_goose_control.c
    ${IEC61850_DIR}/src/iec61850/client/client_sv_control.c
    ${IEC61850_DIR}/src/iec61850/client/client_report.c
    ${IEC61850_DIR}/src/iec61850/client/ied_connection.c
    ${IEC61850_DIR}/src/iec61850/common/iec61850_common.c
    ${IEC61850_DIR}/src/iec61850/server/impl/ied_server.c
    ${IEC61850_DIR}/src/iec61850/server/impl/ied_server_config.c
    ${IEC61850_DIR}/src/iec61850/server/impl/client_connection.c
    ${IEC61850_DIR}/src/iec61850/server/model/model.c
    ${IEC61850_DIR}/src/iec61850/server/model/dynamic_model.c
    ${IEC61850_DIR}/src/iec61850/server/model/cdc.c
    ${IEC61850_DIR}/src/iec61850/server/model/config_file_parser.c
    ${IEC61850_DIR}/src/iec61850/server/mms_mapping/control.c
    ${IEC61850_DIR}/src/iec61850/server/mms_mapping/mms_mapping.c
    ${IEC61850_DIR}/src/iec61850/server/mms_mapping/reporting.c
    ${IEC61850_DIR}/src/iec61850/server/mms_mapping/mms_goose.c
    ${IEC61850_DIR}/src/iec61850/server/mms_mapping/mms_sv.c
    ${IEC61850_DIR}/src/iec61850/server/mms_mapping/logging.c
    ${IEC61850_DIR}/src/logging/log_storage.c
    )

    set (lib_asn1c_SRCS
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/DataAccessError.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/DeleteNamedVariableListRequest.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/constr_SET_OF.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/MmsPdu.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/GetNamedVariableListAttributesResponse.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/BIT_STRING.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ber_tlv_tag.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/constr_SEQUENCE_OF.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/asn_SET_OF.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ReadResponse.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/InformationReport.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ConfirmedServiceRequest.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/DeleteNamedVariableListResponse.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/asn_SEQUENCE_OF.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/VariableAccessSpecification.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/GetVariableAccessAttributesRequest.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/xer_support.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ObjectName.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/NativeEnumerated.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/per_encoder.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/constr_SEQUENCE.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/GetNameListResponse.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/MMSString.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/InitiateErrorPdu.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/IndexRangeSeq.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ConfirmedErrorPDU.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/UnconfirmedService.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/UTF8String.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ServiceError.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/TimeOfDay.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/GetNameListRequest.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/asn_codecs_prim.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/Data.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ScatteredAccessDescription.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ReadRequest.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/per_decoder.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/Identifier.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ServiceSupportOptions.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/Integer8.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ConfirmedServiceResponse.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ParameterSupportOptions.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/Integer16.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ber_tlv_length.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/OCTET_STRING.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/DefineNamedVariableListRequest.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/FloatingPoint.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/xer_encoder.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/Unsigned8.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/BOOLEAN.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/INTEGER.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/UnconfirmedPDU.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/DataSequence.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/constraints.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/der_encoder.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/VisibleString.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/InitiateResponsePdu.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/StructComponent.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/Address.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/Unsigned16.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ber_decoder.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/per_support.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/WriteResponse.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/InitRequestDetail.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/InitiateRequestPdu.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/DefineNamedVariableListResponse.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/NULL.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ListOfVariableSeq.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/UtcTime.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ConcludeResponsePDU.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/AccessResult.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/Integer32.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/GetNamedVariableListAttributesRequest.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/VariableSpecification.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/Unsigned32.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/constr_CHOICE.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/AlternateAccess.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ObjectClass.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/InitResponseDetail.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ConfirmedResponsePdu.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/GetVariableAccessAttributesResponse.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/NativeInteger.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/xer_decoder.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/AlternateAccessSelection.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ConfirmedRequestPdu.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/ConcludeRequestPDU.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/WriteRequest.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/RejectPDU.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/TypeSpecification.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/constr_TYPE.c
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c/GeneralizedTime.c
    )

    set (lib_goose_SRCS
    ${IEC61850_DIR}/src/goose/goose_subscriber.c
    ${IEC61850_DIR}/src/goose/goose_receiver.c
    ${IEC61850_DIR}/src/goose/goose_publisher.c
    )

    set (lib_sv_SRCS
    ${IEC61850_DIR}/src/sampled_values/sv_subscriber.c
    ${IEC61850_DIR}/src/sampled_values/sv_publisher.c
    )

    set (lib_zephyr_SRCS
    )

    set (library_SRCS
        ${lib_common_SRCS}
        ${lib_asn1c_SRCS}
        ${lib_goose_SRCS}
        ${lib_sv_SRCS}
        ${lib_rsession_SRCS}
        ${lib_sntp_SRCS}
        ${lib_zephyr_SRCS}	
    )

    set (hal_SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/ethernet.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/file_provider.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/lib_memory.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/serial_port.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/socket.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/thread.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/time.c
    )
    
  zephyr_library()
  zephyr_library_sources(
    ${library_SRCS}
    ${hal_SRCS}
  )

  zephyr_include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}/config
    ${IEC61850_DIR}/src/common/inc
    ${IEC61850_DIR}/src/goose
    ${IEC61850_DIR}/src/sampled_values
    ${IEC61850_DIR}/src/r_session
    ${IEC61850_DIR}/src/hal/inc
    ${IEC61850_DIR}/src/iec61850/inc
    ${IEC61850_DIR}/src/iec61850/inc_private
    ${IEC61850_DIR}/src/mms/inc
    ${IEC61850_DIR}/src/mms/inc_private
    ${IEC61850_DIR}/src/mms/iso_mms/asn1c
    ${IEC61850_DIR}/src/logging
    ${IEC61850_DIR}/hal/inc
)

endif()